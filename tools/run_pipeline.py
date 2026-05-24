#!/usr/bin/env python3
"""Decompile, recompile, and test selected problems."""

from __future__ import annotations

import argparse
import json
import pathlib
import shlex
import shutil
import sys
import time

import run_tests


def format_template(template: str, values: dict[str, str]) -> str:
  try:
    return template.format(**values)
  except KeyError as exc:
    raise ValueError(f"unknown placeholder {{{exc.args[0]}}}") from exc
  except ValueError as exc:
    raise ValueError(f"invalid template {template!r}: {exc}") from exc


def resolve_template_path(template: str, values: dict[str, str],
                          base_dir: pathlib.Path,
                          allow_empty: bool = False) -> pathlib.Path | None:
  formatted = format_template(template, values).strip()
  if not formatted and allow_empty:
    return None
  path = pathlib.Path(formatted).expanduser()
  if not path.is_absolute():
    path = base_dir / path
  return path.resolve()


def decompile_context(row: dict, tests_root: pathlib.Path,
                      build_dir: pathlib.Path,
                      decompile_dir: pathlib.Path,
                      source_path: pathlib.Path,
                      args: argparse.Namespace) -> dict[str, str]:
  binary_path = build_dir / "original.bin"
  return {
      "binary": str(binary_path),
      "source": str(source_path),
      "work_dir": str(decompile_dir),
      "build_dir": str(build_dir),
      "tests_root": str(tests_root),
      "decompiler_root": str(args.decompiler_root),
      "problem_key": row["key"],
      "split": row["split"],
  }


def ensure_original(row: dict, tests_root: pathlib.Path, build_dir: pathlib.Path,
                    args: argparse.Namespace) -> tuple[bool, dict]:
  binary_path = build_dir / "original.bin"
  if binary_path.exists():
    return True, {
        "status": "compile_ok",
        "binary_path": str(binary_path),
        "cached": True,
    }
  return run_tests.compile_original(
      row,
      tests_root,
      build_dir,
      args.cxx,
      args.cxxflags,
      args.ldflags,
      args.compile_timeout,
  )


def decompile(row: dict, tests_root: pathlib.Path, build_dir: pathlib.Path,
              args: argparse.Namespace) -> tuple[bool, dict]:
  compile_ok, compile_result = ensure_original(row, tests_root, build_dir, args)
  decompile_dir = build_dir / "decompile"
  initial_values = {
      "work_dir": str(decompile_dir),
      "build_dir": str(build_dir),
      "tests_root": str(tests_root),
      "decompiler_root": str(args.decompiler_root),
      "binary": str(build_dir / "original.bin"),
      "problem_key": row["key"],
      "split": row["split"],
  }
  record = {"compile_original": run_tests.truncate_streams(compile_result)}
  if not compile_ok:
    record["status"] = "original_compile_failed"
    return False, record

  try:
    source_path = resolve_template_path(
        args.decompiled_source, initial_values, decompile_dir)
  except ValueError as exc:
    record["status"] = "invalid_decompiled_source_template"
    record["error"] = str(exc)
    return False, record
  assert source_path is not None

  if decompile_dir.exists():
    shutil.rmtree(decompile_dir)
  decompile_dir.mkdir(parents=True, exist_ok=True)
  source_path.parent.mkdir(parents=True, exist_ok=True)

  if not args.decompile_command.strip():
    record.update({
        "status": "decompile_command_missing",
        "source_path": str(source_path),
        "error": "--decompile-command is required when decompiled output is "
                 "not already cached",
    })
    return False, record

  values = decompile_context(row, tests_root, build_dir, decompile_dir,
                             source_path, args)
  try:
    decompile_cmd = shlex.split(format_template(args.decompile_command, values))
    decompiler_cwd = resolve_template_path(
        args.decompiler_cwd, values, args.decompiler_root, allow_empty=True)
  except ValueError as exc:
    record["status"] = "invalid_decompile_template"
    record["error"] = str(exc)
    return False, record
  if not decompile_cmd:
    record["status"] = "decompile_command_missing"
    record["source_path"] = str(source_path)
    return False, record

  decompile_ok, decompile_result = run_tests.run_command(
      decompile_cmd, args.decompile_timeout, cwd=decompiler_cwd)
  record.update({
      "decompiler": run_tests.truncate_streams(decompile_result),
      "decompiler_cwd": str(decompiler_cwd) if decompiler_cwd else "",
      "source_path": str(source_path),
  })
  if not decompile_ok:
    record["status"] = "decompiler_failed"
    return False, record

  if not source_path.exists():
    record["status"] = "source_missing"
    return False, record
  record["status"] = "decompile_ok"
  return True, record


def ensure_decompiled(row: dict, tests_root: pathlib.Path,
                      build_dir: pathlib.Path,
                      args: argparse.Namespace) -> tuple[bool, dict]:
  decompile_dir = build_dir / "decompile"
  values = {
      "work_dir": str(decompile_dir),
      "build_dir": str(build_dir),
      "tests_root": str(tests_root),
      "decompiler_root": str(args.decompiler_root),
      "binary": str(build_dir / "original.bin"),
      "problem_key": row["key"],
      "split": row["split"],
  }
  try:
    source_path = resolve_template_path(
        args.decompiled_source, values, decompile_dir)
  except ValueError as exc:
    return False, {
        "status": "invalid_decompiled_source_template",
        "error": str(exc),
    }
  assert source_path is not None
  if source_path.exists():
    return True, {"status": "decompile_ok", "source_path": str(source_path),
                  "cached": True}
  return decompile(row, tests_root, build_dir, args)


def recompile(row: dict, tests_root: pathlib.Path, build_dir: pathlib.Path,
              args: argparse.Namespace) -> tuple[bool, dict]:
  decompile_ok, decompile_result = ensure_decompiled(
      row, tests_root, build_dir, args)
  record = {"decompile": decompile_result}
  if not decompile_ok:
    record["status"] = "decompile_failed"
    return False, record
  source_path = pathlib.Path(decompile_result["source_path"])
  binary_path = build_dir / "decompile" / "recompiled.bin"
  ok, result = run_tests.compile_source(
      source_path,
      binary_path,
      args.recompile_cxx or args.cxx,
      args.recompile_cxxflags,
      args.recompile_ldflags,
      args.recompile_timeout,
  )
  record["recompile"] = run_tests.truncate_streams(result)
  record["status"] = "recompile_ok" if ok else "recompile_failed"
  return ok, record


def ensure_recompiled(row: dict, tests_root: pathlib.Path,
                      build_dir: pathlib.Path,
                      args: argparse.Namespace) -> tuple[bool, dict]:
  binary_path = build_dir / "decompile" / "recompiled.bin"
  if binary_path.exists():
    return True, {"status": "recompile_ok", "binary_path": str(binary_path),
                  "cached": True}
  return recompile(row, tests_root, build_dir, args)


def test_recompiled(row: dict, tests_root: pathlib.Path,
                    build_dir: pathlib.Path,
                    args: argparse.Namespace) -> tuple[bool, dict]:
  recompile_ok, recompile_result = ensure_recompiled(
      row, tests_root, build_dir, args)
  record = {"recompile": recompile_result}
  if not recompile_ok:
    record["status"] = "recompile_failed"
    return False, record
  binary_path = build_dir / "decompile" / "recompiled.bin"
  tests_ok, tests_result = run_tests.run_tests_binary(
      row,
      tests_root,
      binary_path,
      build_dir / "decompile",
      run_tests.split_values(args.test_groups),
      args.jobs,
      args.timeout,
      bool(args.stop_on_fail),
      args.total_timeout,
  )
  record["tests"] = tests_result
  record["status"] = "tests_ok" if tests_ok else "tests_failed"
  return tests_ok, record


def run_row(row: dict, tests_root: pathlib.Path, build_dir: pathlib.Path,
            args: argparse.Namespace) -> tuple[bool, dict]:
  if args.mode == "decompile":
    return decompile(row, tests_root, build_dir, args)
  if args.mode == "recompile":
    return recompile(row, tests_root, build_dir, args)
  if args.mode in ("test-recompiled", "pipeline"):
    return test_recompiled(row, tests_root, build_dir, args)
  raise AssertionError(args.mode)


def main() -> int:
  parser = argparse.ArgumentParser()
  parser.add_argument("--tests-root", default=".")
  parser.add_argument("--mode",
                      choices=("decompile", "recompile", "test-recompiled",
                               "pipeline"),
                      default="pipeline")
  parser.add_argument("--splits", default="")
  parser.add_argument("--problems", default="")
  parser.add_argument("--start", type=int, default=0)
  parser.add_argument("--limit", type=int, default=0)
  parser.add_argument("--test-groups", default="public private generated")
  parser.add_argument("--decompiler-root", default="decompiler")
  parser.add_argument("--decompiler-cwd", default="{decompiler_root}")
  parser.add_argument("--decompile-command", default="")
  parser.add_argument("--decompiled-source",
                      default="{work_dir}/decompiled.cpp")
  parser.add_argument("--cxx", default="g++")
  parser.add_argument("--cxxflags", default="-std=gnu++11 -O2 -pipe "
                      "-DONLINE_JUDGE")
  parser.add_argument("--ldflags", default="")
  parser.add_argument("--compile-timeout", type=float, default=60.0)
  parser.add_argument("--decompile-timeout", type=float, default=600.0)
  parser.add_argument("--recompile-cxx", default="")
  parser.add_argument("--recompile-cxxflags",
                      default="-std=gnu++17 -O2 -fpermissive")
  parser.add_argument("--recompile-ldflags", default="")
  parser.add_argument("--recompile-timeout", type=float, default=60.0)
  parser.add_argument("--timeout", type=float, default=10.0)
  parser.add_argument("--total-timeout", type=float, default=0.0)
  parser.add_argument("--jobs", type=int, default=1)
  parser.add_argument("--stop-on-fail", type=int, default=1)
  parser.add_argument("--results-dir", default="results")
  args = parser.parse_args()

  tests_root = pathlib.Path(args.tests_root).resolve()
  decompiler_root = pathlib.Path(args.decompiler_root).expanduser()
  if not decompiler_root.is_absolute():
    decompiler_root = tests_root / decompiler_root
  args.decompiler_root = decompiler_root.resolve()

  rows = run_tests.select_rows(
      run_tests.read_manifest(tests_root / "manifest.jsonl"),
      args.splits,
      args.problems,
      args.start,
      args.limit,
  )
  if not rows:
    print("no problems selected", file=sys.stderr)
    return 2

  results_dir = tests_root / args.results_dir
  build_root = tests_root / "build"
  results_dir.mkdir(parents=True, exist_ok=True)
  result_path = results_dir / f"{args.mode}-{time.strftime('%Y%m%d-%H%M%S')}.jsonl"
  overall_ok = True
  with result_path.open("w", encoding="utf-8") as result_file:
    for index, row in enumerate(rows, start=1):
      build_dir = build_root / row["key"]
      print(f"[{index}/{len(rows)}] {row['key']}: {args.mode}", flush=True)
      ok, result = run_row(row, tests_root, build_dir, args)
      record = {
          "key": row["key"],
          "split": row["split"],
          "name": row.get("name"),
          args.mode: result,
      }
      if result.get("tests"):
        tests = result["tests"]
        print(f"[{index}/{len(rows)}] {row['key']}: "
              f"{tests['tests_passed']}/{tests['tests_total']} passed",
              flush=True)
      elif not ok:
        print(f"[{index}/{len(rows)}] {row['key']}: "
              f"{result.get('status', 'failed')}", flush=True)
      overall_ok = overall_ok and ok
      result_file.write(json.dumps(record, ensure_ascii=False) + "\n")
      result_file.flush()

  print(f"results: {result_path}")
  return 0 if overall_ok else 1


if __name__ == "__main__":
  raise SystemExit(main())
