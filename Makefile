PYTHON ?= python3
SPLITS ?=
PROBLEMS ?=
START ?= 0
LIMIT ?= 0
TEST_GROUPS ?= public private generated

CXX ?= g++
CXXFLAGS ?= -std=gnu++11 -O2 -pipe -DONLINE_JUDGE
LDFLAGS ?=
COMPILE_TIMEOUT ?= 60
DECOMPILE_TIMEOUT ?= 600
RECOMPILE_TIMEOUT ?= 60
TIMEOUT ?= 10
TOTAL_TIMEOUT ?= 0
JOBS ?= 1
STOP_ON_FAIL ?= 1
RESULTS_DIR ?= results
EXTRACT_ROOT ?=
EXTRACT_STEMS ?=
EXTRACT_ALL ?= 0

SURI_ROOT ?= /old/home/foxsen/SURI
SURI_PY ?= $(SURI_ROOT)/suri.py
DECOMPILER_PY ?= $(SURI_ROOT)/tools/fsharp_fast_decompiler_wrapper.py
SURI_ARGS ?=
DECOMPILER_ARGS ?= --emit-data-decls --language c++
RECOMPILE_CXX ?= $(CXX)
RECOMPILE_CXXFLAGS ?= -std=gnu++17 -O2 -fpermissive
RECOMPILE_LDFLAGS ?=

PROBLEM_TARGETS := $(shell test -d problems && find problems -mindepth 1 -maxdepth 1 -type d -printf '%f\n' | sort)

.PHONY: help list summary extract-tests build tests test decompile recompile test-recompiled pipeline full first40 clean-build clean-results clean $(PROBLEM_TARGETS)

help:
	@printf '%s\n' \
	  'Targets:' \
	  '  make list                         Print selected problem keys.' \
	  '  make summary                      Count rows and tests in manifest.jsonl.' \
	  '  make extract-tests PROBLEMS=<key> Extract packed tests to tests/*.in|out.' \
	  '  make build                        Compile selected original solutions.' \
	  '  make test                         Compile and test selected original solutions.' \
	  '  make decompile                    Compile originals and emit decompiled C++.' \
	  '  make recompile                    Build decompiled C++ outputs.' \
	  '  make test-recompiled              Run tests on recompiled decompiled outputs.' \
	  '  make pipeline                     Decompile, recompile, then test recompiled outputs.' \
	  '  make full                         Test originals, then run pipeline.' \
	  '  make first40                      Pipeline for the first 40 selected rows.' \
	  '  make <problem-key>                Test one original problem.' \
	  '' \
	  'Selectors:' \
	  '  SPLITS="test valid train"         Empty means all splits.' \
	  '  PROBLEMS="<key> <key>"            Empty means all selected problems.' \
	  '  START=0 LIMIT=0                   Slice after split/problem filtering.' \
	  '  TEST_GROUPS="public private generated"' \
	  '  EXTRACT_ROOT=<dir>                Optional output root for extract-tests.' \
	  '  EXTRACT_STEMS="000 001"           Optional case stems for extract-tests.' \
	  '  EXTRACT_ALL=1                     Allow full selected extraction.' \
	  '' \
	  'Tool variables:' \
	  '  SURI_ROOT=$(SURI_ROOT)' \
	  '  SURI_PY=$(SURI_PY)' \
	  '  DECOMPILER_PY=$(DECOMPILER_PY)' \
	  '  JOBS=$(JOBS) TIMEOUT=$(TIMEOUT) STOP_ON_FAIL=$(STOP_ON_FAIL)'

list:
	$(PYTHON) tools/run_tests.py --bench-root . --mode list --splits "$(SPLITS)" --problems "$(PROBLEMS)" --start "$(START)" --limit "$(LIMIT)"

summary:
	$(PYTHON) tools/run_tests.py --bench-root . --mode summary --splits "$(SPLITS)" --problems "$(PROBLEMS)" --start "$(START)" --limit "$(LIMIT)"

extract-tests:
	$(PYTHON) tools/extract_tests.py \
	  --bench-root . --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --test-groups "$(TEST_GROUPS)" \
	  --stems "$(EXTRACT_STEMS)" $(if $(EXTRACT_ROOT),--output-root "$(EXTRACT_ROOT)",) \
	  $(if $(filter 1,$(EXTRACT_ALL)),--all,) --force

build:
	$(PYTHON) tools/run_tests.py \
	  --bench-root . --mode build --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" \
	  --ldflags "$(LDFLAGS)" --compile-timeout "$(COMPILE_TIMEOUT)" \
	  --results-dir "$(RESULTS_DIR)"

tests test:
	$(PYTHON) tools/run_tests.py \
	  --bench-root . --mode test --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --test-groups "$(TEST_GROUPS)" \
	  --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" --ldflags "$(LDFLAGS)" \
	  --compile-timeout "$(COMPILE_TIMEOUT)" --timeout "$(TIMEOUT)" \
	  --total-timeout "$(TOTAL_TIMEOUT)" --jobs "$(JOBS)" \
	  --stop-on-fail "$(STOP_ON_FAIL)" --results-dir "$(RESULTS_DIR)"

decompile:
	$(PYTHON) tools/run_pipeline.py \
	  --bench-root . --mode decompile --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" \
	  --ldflags "$(LDFLAGS)" --compile-timeout "$(COMPILE_TIMEOUT)" \
	  --decompile-timeout "$(DECOMPILE_TIMEOUT)" --suri-root "$(SURI_ROOT)" \
	  --suri-py "$(SURI_PY)" --suri-args "$(SURI_ARGS)" \
	  --decompiler-py "$(DECOMPILER_PY)" --decompiler-args "$(DECOMPILER_ARGS)" \
	  --results-dir "$(RESULTS_DIR)"

recompile:
	$(PYTHON) tools/run_pipeline.py \
	  --bench-root . --mode recompile --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" \
	  --ldflags "$(LDFLAGS)" --compile-timeout "$(COMPILE_TIMEOUT)" \
	  --decompile-timeout "$(DECOMPILE_TIMEOUT)" --suri-root "$(SURI_ROOT)" \
	  --suri-py "$(SURI_PY)" --suri-args "$(SURI_ARGS)" \
	  --decompiler-py "$(DECOMPILER_PY)" --decompiler-args "$(DECOMPILER_ARGS)" \
	  --recompile-cxx "$(RECOMPILE_CXX)" --recompile-cxxflags "$(RECOMPILE_CXXFLAGS)" \
	  --recompile-ldflags "$(RECOMPILE_LDFLAGS)" --recompile-timeout "$(RECOMPILE_TIMEOUT)" \
	  --results-dir "$(RESULTS_DIR)"

test-recompiled:
	$(PYTHON) tools/run_pipeline.py \
	  --bench-root . --mode test-recompiled --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --test-groups "$(TEST_GROUPS)" \
	  --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" --ldflags "$(LDFLAGS)" \
	  --compile-timeout "$(COMPILE_TIMEOUT)" --decompile-timeout "$(DECOMPILE_TIMEOUT)" \
	  --suri-root "$(SURI_ROOT)" --suri-py "$(SURI_PY)" --suri-args "$(SURI_ARGS)" \
	  --decompiler-py "$(DECOMPILER_PY)" --decompiler-args "$(DECOMPILER_ARGS)" \
	  --recompile-cxx "$(RECOMPILE_CXX)" --recompile-cxxflags "$(RECOMPILE_CXXFLAGS)" \
	  --recompile-ldflags "$(RECOMPILE_LDFLAGS)" --recompile-timeout "$(RECOMPILE_TIMEOUT)" \
	  --timeout "$(TIMEOUT)" --total-timeout "$(TOTAL_TIMEOUT)" --jobs "$(JOBS)" \
	  --stop-on-fail "$(STOP_ON_FAIL)" --results-dir "$(RESULTS_DIR)"

pipeline:
	$(PYTHON) tools/run_pipeline.py \
	  --bench-root . --mode pipeline --splits "$(SPLITS)" --problems "$(PROBLEMS)" \
	  --start "$(START)" --limit "$(LIMIT)" --test-groups "$(TEST_GROUPS)" \
	  --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" --ldflags "$(LDFLAGS)" \
	  --compile-timeout "$(COMPILE_TIMEOUT)" --decompile-timeout "$(DECOMPILE_TIMEOUT)" \
	  --suri-root "$(SURI_ROOT)" --suri-py "$(SURI_PY)" --suri-args "$(SURI_ARGS)" \
	  --decompiler-py "$(DECOMPILER_PY)" --decompiler-args "$(DECOMPILER_ARGS)" \
	  --recompile-cxx "$(RECOMPILE_CXX)" --recompile-cxxflags "$(RECOMPILE_CXXFLAGS)" \
	  --recompile-ldflags "$(RECOMPILE_LDFLAGS)" --recompile-timeout "$(RECOMPILE_TIMEOUT)" \
	  --timeout "$(TIMEOUT)" --total-timeout "$(TOTAL_TIMEOUT)" --jobs "$(JOBS)" \
	  --stop-on-fail "$(STOP_ON_FAIL)" --results-dir "$(RESULTS_DIR)"

full: test pipeline

first40:
	$(MAKE) pipeline LIMIT=40

$(PROBLEM_TARGETS):
	$(PYTHON) tools/run_tests.py \
	  --bench-root . --mode test --splits "" --problems "$@" \
	  --test-groups "$(TEST_GROUPS)" --cxx "$(CXX)" --cxxflags "$(CXXFLAGS)" \
	  --ldflags "$(LDFLAGS)" --compile-timeout "$(COMPILE_TIMEOUT)" \
	  --timeout "$(TIMEOUT)" --jobs "$(JOBS)" --stop-on-fail "$(STOP_ON_FAIL)" \
	  --results-dir "$(RESULTS_DIR)"

clean-build:
	rm -rf build

clean-results:
	rm -rf results

clean: clean-build clean-results
