#!/usr/bin/env python3
"""Extract packed tests back into per-case .in/.out files."""

from __future__ import annotations

import argparse
import pathlib
import shutil
import sqlite3
import sys
from typing import Iterable

import run_tests


def split_values(value: str) -> list[str]:
  return [part for part in value.replace(",", " ").split() if part]


def require_bounded_selection(args: argparse.Namespace) -> None:
  if args.all:
    return
  if args.problems or args.limit or args.stems:
    return
  raise SystemExit(
      "refusing to extract every selected test without --all; pass PROBLEMS, "
      "LIMIT, STEMS, or --all")


def selected_rows(args: argparse.Namespace) -> list[dict]:
  tests_root = pathlib.Path(args.tests_root).resolve()
  rows = run_tests.select_rows(
      run_tests.read_manifest(tests_root / "manifest.jsonl"),
      args.splits,
      args.problems,
      args.start,
      args.limit,
  )
  if not rows:
    print("no problems selected", file=sys.stderr)
    raise SystemExit(2)
  return rows


def query_sqlite_tests(conn: sqlite3.Connection, row: dict,
                       groups: list[str],
                       stems: list[str]) -> list[tuple[str, str, bytes, bytes]]:
  if not groups:
    return []
  where = ["problem_key = ?"]
  params: list[str] = [row["key"]]
  group_placeholders = ",".join("?" for _ in groups)
  where.append(f"group_name IN ({group_placeholders})")
  params.extend(groups)
  if stems:
    stem_placeholders = ",".join("?" for _ in stems)
    where.append(f"stem IN ({stem_placeholders})")
    params.extend(stems)
  query = (
      "SELECT group_name, stem, input, output FROM tests WHERE "
      + " AND ".join(where)
      + " ORDER BY group_name, stem")
  group_order = {group: index for index, group in enumerate(groups)}
  rows = conn.execute(query, params).fetchall()
  rows.sort(key=lambda item: (group_order.get(item[0], len(group_order)),
                             item[1]))
  return rows


def existing_file_conflict(dest_tests_dir: pathlib.Path,
                           rows: Iterable[tuple[str, str, bytes, bytes]]
                           ) -> pathlib.Path | None:
  for group, stem, _input_data, _output_data in rows:
    for suffix in (".in", ".out"):
      path = dest_tests_dir / group / f"{stem}{suffix}"
      if path.exists():
        return path
  return None


def write_rows(dest_tests_dir: pathlib.Path,
               rows: list[tuple[str, str, bytes, bytes]]) -> int:
  for group, stem, input_data, output_data in rows:
    group_dir = dest_tests_dir / group
    group_dir.mkdir(parents=True, exist_ok=True)
    (group_dir / f"{stem}.in").write_bytes(input_data)
    (group_dir / f"{stem}.out").write_bytes(output_data)
  return len(rows)


def destination_tests_dir(output_root: pathlib.Path, row: dict) -> pathlib.Path:
  return output_root / row["problem_path"] / "tests"


def extract_sqlite(args: argparse.Namespace, rows: list[dict]) -> int:
  tests_root = pathlib.Path(args.tests_root).resolve()
  output_root = pathlib.Path(args.output_root).expanduser().resolve() if (
      args.output_root) else tests_root
  groups = split_values(args.test_groups)
  stems = split_values(args.stems)
  total = 0
  with sqlite3.connect(tests_root / "tests.sqlite") as conn:
    for index, row in enumerate(rows, start=1):
      test_rows = query_sqlite_tests(conn, row, groups, stems)
      dest_tests_dir = destination_tests_dir(output_root, row)
      if args.force and dest_tests_dir.exists():
        shutil.rmtree(dest_tests_dir)
      elif not args.force:
        conflict = existing_file_conflict(dest_tests_dir, test_rows)
        if conflict is not None:
          raise FileExistsError(
              f"refusing to overwrite existing test file: {conflict}; "
              "pass --force")
      count = write_rows(dest_tests_dir, test_rows)
      total += count
      print(f"[{index}/{len(rows)}] {row['key']}: wrote {count} tests",
            flush=True)
  return total


def main() -> int:
  parser = argparse.ArgumentParser()
  parser.add_argument("--tests-root", default=".")
  parser.add_argument("--output-root", default="",
                      help=("Directory receiving problems/<key>/tests. "
                            "Defaults to tests-root."))
  parser.add_argument("--splits", default="")
  parser.add_argument("--problems", default="")
  parser.add_argument("--start", type=int, default=0)
  parser.add_argument("--limit", type=int, default=0)
  parser.add_argument("--test-groups", default="public private generated")
  parser.add_argument("--stems", default="",
                      help="Optional space/comma-separated case stems, e.g. 000 001.")
  parser.add_argument("--force", action="store_true",
                      help="Remove each destination tests directory before writing.")
  parser.add_argument("--all", action="store_true",
                      help="Allow extracting every row selected by SPLITS/START.")
  args = parser.parse_args()

  require_bounded_selection(args)
  rows = selected_rows(args)
  total = extract_sqlite(args, rows)
  print(f"extracted {total} tests")
  return 0


if __name__ == "__main__":
  raise SystemExit(main())
