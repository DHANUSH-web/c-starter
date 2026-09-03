build:
	@cmake --preset debug
	@cmake --build out/debug

build-release:
	@cmake --preset release
	@cmake --build out/release

build-all: build build-release

build-raw:
	@mkdir -p out/debug
	@gcc.exe -std=c17 -Iinclude  src/core.c src/main.c -o out/debug/c-codingbat.exe
	@gcc.exe -std=c17 -Iinclude -Iextras/unity/src tests/test_core.c src/core.c extras/unity/src/unity.c -o out/debug/c-codingbat-tests.exe

build-raw-release:
	@mkdir -p out/release
	@gcc.exe -std=c17 -O3 -march=native -Iinclude src/core.c src/main.c -o out/release/c-codingbat.exe
	@gcc.exe -std=c17 -O3 -march=native -Iinclude -Iextras/unity/src tests/test_core.c src/core.c extras/unity/src/unity.c  -o out/release/c-codingbat-tests.exe

build-raw-all: build-raw build-raw-release

run:
	@out/debug/c-codingbat.exe

run-release:
	@out/release/c-codingbat.exe

test:
	@out/debug/c-codingbat-tests.exe

test-release:
	@out/release/c-codingbat-tests.exe

clean:
	@rm -rf out/debug

clean-release:
	@rm -rf out/release

clean-all:
	@rm -rf out

.PHONY: build build-release build-all build-raw build-raw-release build-raw-all run run-release test test-release clean clean-release clean-all
