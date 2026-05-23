#!/usr/bin/env python3
"""Decompile, recompile, and test selected benchmark problems."""

from __future__ import annotations

import argparse
import json
import pathlib
import shlex
import shutil
import sys
import time

import run_tests


def find_suri_metadata(suri_out_dir: pathlib.Path,
                       binary_path: pathlib.Path) -> pathlib.Path | None:
  preferred = suri_out_dir / f"{binary_path.stem}.json"
  if preferred.exists():
    return preferred
  json_files = sorted(suri_out_dir.glob("*.json"))
  if len(json_files) == 1:
    return json_files[0]
  for path in json_files:
    if path.stem == binary_path.name:
      return path
  return None


def ensure_original(row: dict, bench_root: pathlib.Path, build_dir: pathlib.Path,
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
      bench_root,
      build_dir,
      args.cxx,
      args.cxxflags,
      args.ldflags,
      args.compile_timeout,
  )


def decompile(row: dict, bench_root: pathlib.Path, build_dir: pathlib.Path,
              args: argparse.Namespace) -> tuple[bool, dict]:
  compile_ok, compile_result = ensure_original(row, bench_root, build_dir, args)
  decompile_dir = build_dir / "decompile"
  suri_out_dir = decompile_dir / "suri"
  source_path = decompile_dir / "decompiled.cpp"
  record = {"compile_original": run_tests.truncate_streams(compile_result)}
  if not compile_ok:
    record["status"] = "original_compile_failed"
    return False, record

  if decompile_dir.exists():
    shutil.rmtree(decompile_dir)
  suri_out_dir.mkdir(parents=True, exist_ok=True)
  original_binary = build_dir / "original.bin"

  suri_cmd = [
      args.python,
      str(args.suri_py),
      str(original_binary),
      "--ofolder",
      str(suri_out_dir),
      "--without-compile",
  ] + shlex.split(args.suri_args)
  suri_ok, suri_result = run_tests.run_command(
      suri_cmd, args.decompile_timeout, cwd=args.suri_root)
  record.update({
      "suri": run_tests.truncate_streams(suri_result),
      "source_path": str(source_path),
  })
  if not suri_ok:
    record["status"] = "suri_failed"
    return False, record

  metadata_path = find_suri_metadata(suri_out_dir, original_binary)
  if metadata_path is None:
    record["status"] = "metadata_missing"
    record["metadata_candidates"] = [str(p) for p in sorted(
        suri_out_dir.glob("*.json"))]
    return False, record

  decompiler_cmd = [
      args.python,
      str(args.decompiler_py),
      str(metadata_path),
      "--binary",
      str(original_binary),
      "-o",
      str(source_path),
  ] + shlex.split(args.decompiler_args)
  decompiler_ok, decompiler_result = run_tests.run_command(
      decompiler_cmd, args.decompile_timeout, cwd=args.suri_root)
  record.update({
      "metadata_path": str(metadata_path),
      "decompiler": run_tests.truncate_streams(decompiler_result),
  })
  if not decompiler_ok:
    record["status"] = "decompiler_failed"
    return False, record
  if not source_path.exists():
    record["status"] = "source_missing"
    return False, record
  record["status"] = "decompile_ok"
  return True, record


def ensure_decompiled(row: dict, bench_root: pathlib.Path,
                      build_dir: pathlib.Path,
                      args: argparse.Namespace) -> tuple[bool, dict]:
  source_path = build_dir / "decompile" / "decompiled.cpp"
  if source_path.exists():
    return True, {"status": "decompile_ok", "source_path": str(source_path),
                  "cached": True}
  return decompile(row, bench_root, build_dir, args)


def recompile(row: dict, bench_root: pathlib.Path, build_dir: pathlib.Path,
              args: argparse.Namespace) -> tuple[bool, dict]:
  decompile_ok, decompile_result = ensure_decompiled(
      row, bench_root, build_dir, args)
  record = {"decompile": decompile_result}
  if not decompile_ok:
    record["status"] = "decompile_failed"
    return False, record
  source_path = build_dir / "decompile" / "decompiled.cpp"
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


def ensure_recompiled(row: dict, bench_root: pathlib.Path,
                      build_dir: pathlib.Path,
                      args: argparse.Namespace) -> tuple[bool, dict]:
  binary_path = build_dir / "decompile" / "recompiled.bin"
  if binary_path.exists():
    return True, {"status": "recompile_ok", "binary_path": str(binary_path),
                  "cached": True}
  return recompile(row, bench_root, build_dir, args)


def test_recompiled(row: dict, bench_root: pathlib.Path,
                    build_dir: pathlib.Path,
                    args: argparse.Namespace) -> tuple[bool, dict]:
  recompile_ok, recompile_result = ensure_recompiled(
      row, bench_root, build_dir, args)
  record = {"recompile": recompile_result}
  if not recompile_ok:
    record["status"] = "recompile_failed"
    return False, record
  binary_path = build_dir / "decompile" / "recompiled.bin"
  tests_ok, tests_result = run_tests.run_tests_binary(
      row,
      bench_root,
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


def run_row(row: dict, bench_root: pathlib.Path, build_dir: pathlib.Path,
            args: argparse.Namespace) -> tuple[bool, dict]:
  if args.mode == "decompile":
    return decompile(row, bench_root, build_dir, args)
  if args.mode == "recompile":
    return recompile(row, bench_root, build_dir, args)
  if args.mode in ("test-recompiled", "pipeline"):
    return test_recompiled(row, bench_root, build_dir, args)
  raise AssertionError(args.mode)


def main() -> int:
  parser = argparse.ArgumentParser()
  parser.add_argument("--bench-root", default=".")
  parser.add_argument("--mode",
                      choices=("decompile", "recompile", "test-recompiled",
                               "pipeline"),
                      default="pipeline")
  parser.add_argument("--splits", default="")
  parser.add_argument("--problems", default="")
  parser.add_argument("--start", type=int, default=0)
  parser.add_argument("--limit", type=int, default=0)
  parser.add_argument("--test-groups", default="public private generated")
  parser.add_argument("--python", default="python3")
  parser.add_argument("--suri-root", default=str(pathlib.Path.home() /
                      "code/SURI"))
  parser.add_argument("--suri-py", default="")
  parser.add_argument("--suri-args", default="")
  parser.add_argument("--decompiler-py", default="")
  parser.add_argument("--decompiler-args",
                      default="--emit-data-decls --language c++")
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

  bench_root = pathlib.Path(args.bench_root).resolve()
  args.suri_root = pathlib.Path(args.suri_root).expanduser().resolve()
  args.suri_py = pathlib.Path(args.suri_py).expanduser().resolve() if (
      args.suri_py) else args.suri_root / "suri.py"
  args.decompiler_py = pathlib.Path(args.decompiler_py).expanduser().resolve(
  ) if args.decompiler_py else args.suri_root / "tools" / (
      "fsharp_fast_decompiler_wrapper.py")

  for path, label in ((args.suri_py, "suri.py"),
                      (args.decompiler_py, "decompiler wrapper")):
    if not path.exists():
      print(f"{label} not found: {path}", file=sys.stderr)
      return 2

  rows = run_tests.select_rows(
      run_tests.read_manifest(bench_root / "manifest.jsonl"),
      args.splits,
      args.problems,
      args.start,
      args.limit,
  )
  if not rows:
    print("no problems selected", file=sys.stderr)
    return 2

  results_dir = bench_root / args.results_dir
  build_root = bench_root / "build"
  results_dir.mkdir(parents=True, exist_ok=True)
  result_path = results_dir / f"{args.mode}-{time.strftime('%Y%m%d-%H%M%S')}.jsonl"
  overall_ok = True
  with result_path.open("w", encoding="utf-8") as result_file:
    for index, row in enumerate(rows, start=1):
      build_dir = build_root / row["key"]
      print(f"[{index}/{len(rows)}] {row['key']}: {args.mode}", flush=True)
      ok, result = run_row(row, bench_root, build_dir, args)
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
