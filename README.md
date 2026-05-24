# decompile_tests

This directory was generated from qualified CodeContests rows.
Problem directories contain real copies of solution.cc and metadata.json.
Tests are stored in tests.sqlite by default, not as per-case symlinks.

Cloning the full repository:

`tests.sqlite` is stored with Git LFS. A normal `git clone` downloads the real
SQLite file only when Git LFS is installed and enabled on the client. Otherwise
the checkout may contain a small pointer file instead.

```sh
git lfs install
git clone git@github.com:foxsen/decompile_tests.git
cd decompile_tests
git lfs pull
```

If the repository was cloned before installing Git LFS, run `git lfs install`
and then `git lfs pull` inside the repository.

Useful commands:

```sh
make summary
make extract-tests PROBLEMS='<problem-key>'
make test SPLITS=test LIMIT=1
make pipeline SPLITS=test LIMIT=1
make pipeline PROBLEMS='<problem-key>'
```

Decompiler integration:

`make pipeline` expects a decompiler command template. By default,
`DECOMPILER_ROOT` points at `decompiler` under this repository. The command
template may use these placeholders:

- `{binary}`: compiled original binary
- `{source}`: expected decompiled C++ output path
- `{work_dir}`: per-problem decompile working directory
- `{build_dir}`: per-problem build directory
- `{tests_root}`: repository root
- `{decompiler_root}`: configured decompiler directory
- `{problem_key}` and `{split}`: manifest metadata

Example:

```sh
make pipeline SPLITS=test LIMIT=1 \
  DECOMPILER_ROOT=/path/to/decompiler \
  DECOMPILE_COMMAND='{decompiler_root}/decompile {binary} -o {source}'
```

Use `DECOMPILER_CWD` if the command must run from a different directory.
