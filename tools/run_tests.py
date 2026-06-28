#!/usr/bin/env python3
"""Compile selected C++ solutions and run CodeContests-style tests."""

from __future__ import annotations

import argparse
import concurrent.futures
import json
import math
import os
import pathlib
import shlex
import signal
import sqlite3
import subprocess
import sys
import tempfile
import time
from dataclasses import dataclass
from typing import Iterable


NUMERIC_TOLERANCE = 1e-5


@dataclass(frozen=True)
class TestCase:
  group: str
  stem: str
  input_data: str
  output_data: str


def read_manifest(path: pathlib.Path) -> list[dict]:
  with path.open(encoding="utf-8") as f:
    return [json.loads(line) for line in f if line.strip()]


def split_values(value: str) -> list[str]:
  return [part for part in value.replace(",", " ").split() if part]


def select_rows(rows: list[dict], splits: str, problems: str, start: int,
                limit: int) -> list[dict]:
  split_set = set(split_values(splits)) if splits else set()
  problem_set = set(split_values(problems)) if problems else set()
  selected = []
  for row in rows:
    if split_set and row["split"] not in split_set:
      continue
    if problem_set and row["key"] not in problem_set:
      continue
    selected.append(row)
  if start:
    selected = selected[start:]
  if limit:
    selected = selected[:limit]
  return selected


def tokens(value: str) -> list[str]:
  return value.lower().split()


def parse_number(value: str):
  try:
    return ("int", int(value, 10))
  except ValueError:
    pass
  try:
    parsed = float(value)
  except (OverflowError, ValueError):
    return None
  if math.isnan(parsed) or math.isinf(parsed):
    return None
  return ("float", parsed)


def outputs_match(actual: str, expected: str) -> bool:
  actual_parts = tokens(actual)
  expected_parts = tokens(expected)
  if actual_parts == expected_parts:
    return True
  if len(actual_parts) != len(expected_parts):
    return False
  for actual_token, expected_token in zip(actual_parts, expected_parts):
    actual_number = parse_number(actual_token)
    expected_number = parse_number(expected_token)
    if actual_number is None or expected_number is None:
      if actual_token != expected_token:
        return False
      continue
    if "float" in (actual_number[0], expected_number[0]):
      try:
        diff = abs(float(actual_number[1]) - float(expected_number[1]))
      except OverflowError:
        return False
      if diff >= NUMERIC_TOLERANCE:
        return False
    elif actual_number[1] != expected_number[1]:
      return False
  return True


def preview_text(value: str, limit: int = 4000) -> str:
  return value[:limit]


def preview_lines(value: str, limit: int = 8) -> list[str]:
  return value.splitlines()[:limit]


def diff_preview(actual: str, expected: str, limit: int = 8) -> str:
  actual_lines = preview_lines(actual, limit)
  expected_lines = preview_lines(expected, limit)
  lines = []
  for index, (expected_line, actual_line) in enumerate(
      zip(expected_lines, actual_lines), start=1):
    if expected_line != actual_line:
      lines.append(f"line {index}:")
      lines.append(f"  expected: {expected_line}")
      lines.append(f"  actual:   {actual_line}")
      if len(lines) >= limit * 3:
        break
  if len(expected_lines) != len(actual_lines) and len(lines) < limit * 3:
    lines.append("line count differs:")
    lines.append(f"  expected lines: {len(expected.splitlines())}")
    lines.append(f"  actual lines:   {len(actual.splitlines())}")
  return "\n".join(lines)


def normalize_case_key(group: str, stem: str) -> tuple[str, str]:
  return (str(group), str(stem))


def load_fixture_annotations(tests_root: pathlib.Path,
                             annotations_path: str) -> dict:
  path_text = annotations_path.strip()
  if not path_text:
    return {}
  path = pathlib.Path(path_text).expanduser()
  if not path.is_absolute():
    path = tests_root / path
  if not path.exists():
    return {}
  with path.open(encoding="utf-8") as f:
    data = json.load(f)
  problem_entries = data.get("problems", data)
  annotations: dict[str, dict] = {}
  for problem_key, problem_annotation in problem_entries.items():
    if not isinstance(problem_annotation, dict):
      raise ValueError(f"invalid fixture annotation for {problem_key}")
    cases = problem_annotation.get("cases", [])
    problem_defaults = {
        key: value
        for key, value in problem_annotation.items()
        if key != "cases"
    }
    case_annotations: dict[tuple[str, str], dict] = {}
    for case in cases:
      if not isinstance(case, dict):
        raise ValueError(f"invalid fixture case annotation for {problem_key}")
      group = case.get("group")
      stem = case.get("stem")
      if group is None or stem is None:
        raise ValueError(f"fixture case missing group/stem for {problem_key}")
      merged = dict(problem_defaults)
      merged.update(case)
      case_annotations[normalize_case_key(group, stem)] = merged
    entry = dict(problem_defaults)
    if case_annotations:
      entry["cases"] = case_annotations
    if entry:
      annotations[problem_key] = entry
  return annotations


def fixture_case_annotations(
    annotation: dict | None,
) -> dict[tuple[str, str], dict] | None:
  if not annotation:
    return None
  cases = annotation.get("cases")
  return cases if isinstance(cases, dict) else None


def annotated_compile_cxxflags(annotation: dict | None,
                               default_cxxflags: str) -> str:
  if not annotation:
    return default_cxxflags
  cxxflags = annotation.get("compile_cxxflags")
  if isinstance(cxxflags, str) and cxxflags.strip():
    return cxxflags
  return default_cxxflags


def attach_ignored_failure_annotation(
    result: dict,
    ignored_cases: dict[tuple[str, str], dict] | None,
) -> bool:
  if result.get("passed") or not ignored_cases:
    return False
  key = normalize_case_key(result.get("group", ""), result.get("stem", ""))
  annotation = ignored_cases.get(key)
  if annotation is None:
    return False
  if not annotation.get("ignore_failure", False):
    return False
  result["ignored_failure"] = True
  result["fixture_annotation"] = annotation
  return True


def iter_file_tests(tests_dir: pathlib.Path,
                    groups: Iterable[str]) -> list[TestCase]:
  cases = []
  for group in groups:
    group_dir = tests_dir / group
    if not group_dir.exists():
      continue
    for input_path in sorted(group_dir.glob("*.in")):
      output_path = input_path.with_suffix(".out")
      if output_path.exists():
        input_data = input_path.read_text(encoding="utf-8", errors="replace")
        output_data = output_path.read_text(encoding="utf-8", errors="replace")
        cases.append(TestCase(group, input_path.stem, input_data, output_data))
  return cases


def iter_sqlite_tests(db_path: pathlib.Path, problem_key: str,
                      groups: Iterable[str]) -> list[TestCase]:
  group_values = list(groups)
  if not group_values:
    return []
  placeholders = ",".join("?" for _ in group_values)
  query = (
      "SELECT group_name, stem, input, output FROM tests "
      f"WHERE problem_key = ? AND group_name IN ({placeholders}) "
      "ORDER BY group_name, stem")
  group_order = {group: index for index, group in enumerate(group_values)}
  with sqlite3.connect(db_path) as conn:
    rows = conn.execute(query, [problem_key, *group_values]).fetchall()
  cases = [
      TestCase(
          group,
          stem,
          input_blob.decode("utf-8", errors="replace"),
          output_blob.decode("utf-8", errors="replace"),
      )
      for group, stem, input_blob, output_blob in rows
  ]
  cases.sort(key=lambda case: (group_order.get(case.group, len(group_order)),
                              case.stem))
  return cases


def iter_tests(row: dict, tests_root: pathlib.Path,
               groups: Iterable[str]) -> list[TestCase]:
  if row.get("tests_storage") == "sqlite":
    return iter_sqlite_tests(tests_root / row.get("tests_path", "tests.sqlite"),
                             row["key"], groups)
  return iter_file_tests(tests_root / row["tests_path"], groups)


def run_command(cmd: list[str], timeout: float,
                cwd: pathlib.Path | None = None) -> tuple[bool, dict]:
  started = time.monotonic()
  try:
    completed = subprocess.run(
        cmd,
        cwd=str(cwd) if cwd else None,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=timeout,
    )
  except subprocess.TimeoutExpired as exc:
    return False, {
        "status": "timeout",
        "command": cmd,
        "cwd": str(cwd) if cwd else "",
        "duration_seconds": time.monotonic() - started,
        "stdout": exc.stdout or "",
        "stderr": exc.stderr or "",
    }
  except OSError as exc:
    return False, {
        "status": "spawn_failed",
        "command": cmd,
        "cwd": str(cwd) if cwd else "",
        "duration_seconds": time.monotonic() - started,
        "stdout": "",
        "stderr": str(exc),
    }
  ok = completed.returncode == 0
  return ok, {
      "status": "ok" if ok else "failed",
      "command": cmd,
      "cwd": str(cwd) if cwd else "",
      "returncode": completed.returncode,
      "duration_seconds": time.monotonic() - started,
      "stdout": completed.stdout,
      "stderr": completed.stderr,
  }


def truncate_streams(summary: dict) -> dict:
  for key in ("stdout", "stderr"):
    if isinstance(summary.get(key), str) and len(summary[key]) > 4000:
      summary[key] = summary[key][:4000]
  return summary


def compile_source(source_path: pathlib.Path, binary_path: pathlib.Path,
                   cxx: str, cxxflags: str, ldflags: str,
                   timeout: float) -> tuple[bool, dict]:
  binary_path.parent.mkdir(parents=True, exist_ok=True)
  cmd = [cxx] + shlex.split(cxxflags) + [str(source_path), "-o",
                                        str(binary_path)]
  cmd += shlex.split(ldflags)
  ok, result = run_command(cmd, timeout)
  result["status"] = "compile_ok" if ok else (
      "compile_timeout" if result["status"] == "timeout" else "compile_failed")
  result["binary_path"] = str(binary_path)
  return ok, result


def compile_original(row: dict, tests_root: pathlib.Path,
                     build_dir: pathlib.Path, cxx: str, cxxflags: str,
                     ldflags: str, timeout: float,
                     annotation: dict | None = None) -> tuple[bool, dict]:
  effective_cxxflags = annotated_compile_cxxflags(annotation, cxxflags)
  return compile_source(
      tests_root / row["solution_path"],
      build_dir / "original.bin",
      cxx,
      effective_cxxflags,
      ldflags,
      timeout,
  )


def run_one_test(binary_path: pathlib.Path, case: TestCase, row: dict,
                 timeout: float, work_parent: pathlib.Path) -> dict:
  expected = case.output_data
  test_input = case.input_data
  input_file = row.get("input_file") or ""
  output_file = row.get("output_file") or ""
  started = time.monotonic()

  with tempfile.TemporaryDirectory(
      prefix=f"{case.group}_{case.stem}_", dir=work_parent) as tmp:
    cwd = pathlib.Path(tmp)
    stdin_data = test_input
    if input_file:
      input_path = cwd / input_file
      input_path.parent.mkdir(parents=True, exist_ok=True)
      input_path.write_text(test_input, encoding="utf-8")
      stdin_data = ""

    process = subprocess.Popen(
        [str(binary_path)],
        stdin=subprocess.PIPE if stdin_data else subprocess.DEVNULL,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        cwd=cwd,
        start_new_session=True,
    )
    try:
      stdout_data, stderr_data = process.communicate(
          input=stdin_data.encode("utf-8") if stdin_data else None,
          timeout=timeout,
      )
    except subprocess.TimeoutExpired as exc:
      try:
        os.killpg(process.pid, signal.SIGKILL)
      except ProcessLookupError:
        pass
      stdout_data, stderr_data = process.communicate()
      return {
          "group": case.group,
          "stem": case.stem,
          "status": "timeout",
          "passed": False,
          "duration_seconds": time.monotonic() - started,
          "stdout": (exc.stdout or stdout_data or b"").decode(
              "utf-8", errors="replace"),
          "stderr": (exc.stderr or stderr_data or b"").decode(
              "utf-8", errors="replace"),
      }
    finally:
      try:
        os.killpg(process.pid, signal.SIGKILL)
      except ProcessLookupError:
        pass

    stdout_text = stdout_data.decode("utf-8", errors="replace")
    stderr_text = stderr_data.decode("utf-8", errors="replace")
    if output_file:
      output_path = cwd / output_file
      actual = output_path.read_text(
          encoding="utf-8", errors="replace") if output_path.exists() else ""
    else:
      actual = stdout_text

  try:
    passed = process.returncode == 0 and outputs_match(actual, expected)
  except Exception as exc:
    return {
        "group": case.group,
        "stem": case.stem,
        "status": "compare_error",
        "passed": False,
        "returncode": process.returncode,
        "duration_seconds": time.monotonic() - started,
        "stdout": preview_text(actual),
        "expected_output": preview_text(expected),
        "output_diff": diff_preview(actual, expected),
        "stderr": (stderr_text + f"\ncompare_error: {exc}")[:4000],
    }
  output_diff = "" if passed else diff_preview(actual, expected)
  return {
      "group": case.group,
      "stem": case.stem,
      "status": "ok" if process.returncode == 0 else "runtime_failed",
      "passed": passed,
      "returncode": process.returncode,
      "duration_seconds": time.monotonic() - started,
      "stdout": preview_text(actual),
      "expected_output": preview_text(expected) if not passed else "",
      "output_diff": output_diff,
      "stderr": stderr_text[:4000],
  }


def run_tests_binary(row: dict, tests_root: pathlib.Path,
                     binary_path: pathlib.Path, build_dir: pathlib.Path,
                     test_groups: list[str], jobs: int, timeout: float,
                     stop_on_fail: bool,
                     total_timeout: float = 0.0,
                     ignored_cases: dict[tuple[str, str], dict] | None = None,
                     ) -> tuple[bool, dict]:
  cases = iter_tests(row, tests_root, test_groups)
  work_parent = build_dir / "work"
  work_parent.mkdir(parents=True, exist_ok=True)
  results = []
  started = time.monotonic()
  deadline = started + total_timeout if total_timeout > 0 else None
  timed_out = False

  if stop_on_fail or jobs <= 1 or deadline is not None:
    for case in cases:
      remaining_timeout = timeout
      if deadline is not None:
        time_left = deadline - time.monotonic()
        if time_left <= 0:
          timed_out = True
          break
        remaining_timeout = min(remaining_timeout, time_left)
      result = run_one_test(binary_path, case, row, remaining_timeout,
                            work_parent)
      ignored_failure = attach_ignored_failure_annotation(
          result, ignored_cases)
      results.append(result)
      if not result["passed"] and stop_on_fail and not ignored_failure:
        break
  else:
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as executor:
      futures = [
          executor.submit(run_one_test, binary_path, case, row, timeout,
                          work_parent)
          for case in cases
      ]
      for future in concurrent.futures.as_completed(futures):
        result = future.result()
        attach_ignored_failure_annotation(result, ignored_cases)
        results.append(result)

  passed_count = sum(1 for result in results if result["passed"])
  ignored_failure_count = sum(
      1 for result in results if result.get("ignored_failure"))
  effective_passed_count = passed_count + ignored_failure_count
  first_failure = next(
      (r for r in results
       if not r["passed"] and not r.get("ignored_failure")),
      None)
  first_ignored_failure = next(
      (r for r in results if r.get("ignored_failure")),
      None)
  ok = first_failure is None and effective_passed_count == len(cases)
  if timed_out and first_failure is None:
    next_case = cases[len(results)] if len(results) < len(cases) else None
    first_failure = {
        "group": next_case.group if next_case else "",
        "stem": next_case.stem if next_case else "",
        "status": "test_run_timeout",
        "passed": False,
        "duration_seconds": time.monotonic() - started,
        "stdout": "",
        "stderr": "",
    }
    ok = False
  return ok, {
      "status": ("tests_ok" if ok else
                 "tests_timeout" if timed_out else "tests_failed"),
      "test_groups": test_groups,
      "tests_total": len(cases),
      "tests_run": len(results),
      "tests_passed": passed_count,
      "tests_effective_passed": effective_passed_count,
      "ignored_failures": ignored_failure_count,
      "duration_seconds": time.monotonic() - started,
      "total_timeout_seconds": total_timeout,
      "first_failure": first_failure,
      "first_ignored_failure": first_ignored_failure,
  }


def selected_rows(args: argparse.Namespace) -> list[dict]:
  tests_root = pathlib.Path(args.tests_root).resolve()
  rows = select_rows(
      read_manifest(tests_root / "manifest.jsonl"),
      args.splits,
      args.problems,
      args.start,
      args.limit,
  )
  if not rows:
    print("no problems selected", file=sys.stderr)
    raise SystemExit(2)
  return rows


def write_result(path: pathlib.Path, record: dict) -> None:
  with path.open("a", encoding="utf-8") as f:
    f.write(json.dumps(record, ensure_ascii=False) + "\n")


def main() -> int:
  parser = argparse.ArgumentParser()
  parser.add_argument("--tests-root", default=".")
  parser.add_argument("--mode", choices=("list", "summary", "build", "test"),
                      default="test")
  parser.add_argument("--splits", default="")
  parser.add_argument("--problems", default="")
  parser.add_argument("--start", type=int, default=0)
  parser.add_argument("--limit", type=int, default=0)
  parser.add_argument("--test-groups", default="public private generated")
  parser.add_argument("--cxx", default="g++")
  parser.add_argument("--cxxflags", default="-std=gnu++11 -O2 -pipe "
                      "-DONLINE_JUDGE")
  parser.add_argument("--ldflags", default="")
  parser.add_argument("--compile-timeout", type=float, default=60.0)
  parser.add_argument("--timeout", type=float, default=10.0)
  parser.add_argument("--total-timeout", type=float, default=0.0)
  parser.add_argument("--jobs", type=int, default=1)
  parser.add_argument("--stop-on-fail", type=int, default=1)
  parser.add_argument("--results-dir", default="results")
  parser.add_argument("--fixture-annotations", default="fixture_annotations.json")
  args = parser.parse_args()

  tests_root = pathlib.Path(args.tests_root).resolve()
  try:
    fixture_annotations = load_fixture_annotations(
        tests_root, args.fixture_annotations)
  except (OSError, ValueError, json.JSONDecodeError) as exc:
    print(f"failed to load fixture annotations: {exc}", file=sys.stderr)
    return 2
  rows = selected_rows(args)

  if args.mode == "list":
    for row in rows:
      print(row["key"])
    return 0
  if args.mode == "summary":
    total_tests = sum(row.get("test_counts", {}).get("total", 0)
                      for row in rows)
    by_split = {}
    for row in rows:
      by_split[row["split"]] = by_split.get(row["split"], 0) + 1
    print(json.dumps({
        "problems": len(rows),
        "tests": total_tests,
        "splits": by_split,
    }, indent=2, sort_keys=True))
    return 0

  results_dir = tests_root / args.results_dir
  build_root = tests_root / "build"
  results_dir.mkdir(parents=True, exist_ok=True)
  run_id = time.strftime("%Y%m%d-%H%M%S")
  result_path = results_dir / f"{args.mode}-{run_id}.jsonl"
  test_groups = split_values(args.test_groups)
  overall_ok = True

  for index, row in enumerate(rows, start=1):
    build_dir = build_root / row["key"]
    annotation = fixture_annotations.get(row["key"])
    print(f"[{index}/{len(rows)}] {row['key']}: compile", flush=True)
    compile_ok, compile_result = compile_original(
        row, tests_root, build_dir, args.cxx, args.cxxflags, args.ldflags,
        args.compile_timeout, annotation)
    record = {
        "key": row["key"],
        "split": row["split"],
        "name": row.get("name"),
        "compile": truncate_streams(compile_result),
    }
    if not compile_ok:
      overall_ok = False
      write_result(result_path, record)
      print(f"[{index}/{len(rows)}] {row['key']}: compile failed", flush=True)
      continue
    if args.mode == "test":
      print(f"[{index}/{len(rows)}] {row['key']}: run tests", flush=True)
      tests_ok, test_result = run_tests_binary(
          row,
          tests_root,
          build_dir / "original.bin",
          build_dir,
          test_groups,
          args.jobs,
          args.timeout,
          bool(args.stop_on_fail),
          args.total_timeout,
          fixture_case_annotations(annotation),
      )
      record["tests"] = test_result
      overall_ok = overall_ok and tests_ok
      print(f"[{index}/{len(rows)}] {row['key']}: "
            f"{test_result['tests_passed']}/{test_result['tests_total']} "
            "passed", flush=True)
    write_result(result_path, record)

  print(f"results: {result_path}")
  return 0 if overall_ok else 1


if __name__ == "__main__":
  raise SystemExit(main())
