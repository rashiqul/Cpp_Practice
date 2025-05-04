# =========================================
# Makefile for C++ Modular Project with Tests + Coverage
# Author: Rashiqul
# =========================================

# -----------------------------------------
# Setup and configure the build directory
# -----------------------------------------
configure:
	@echo "[Config] Cleaning and setting up build directory..."
	rm -rf build
	mkdir build
	cd build && cmake ..
	@echo "[Config] Done. You can now run 'make build' or 'make run'"

# -----------------------------------------
# Compile the project (depends on configure)
# -----------------------------------------
build: configure
	cd build && cmake --build .

# -----------------------------------------
# Clean build files and leftover coverage artifacts
# -----------------------------------------
clean:
	rm -rf build
	find . -name "*.gcda" -o -name "*.gcno" -o -name "*.gcov" -delete

# -----------------------------------------
# Run the main executable
# -----------------------------------------
run: build
	./build/main/Executable

# -----------------------------------------
# Run all tests using GoogleTest directly
# -----------------------------------------
run-tests: build
	@echo "[Test] Running unit tests via GoogleTest..."
	./build/test/TestExecutable

# -----------------------------------------
# Show test results manually (alternative to run-tests)
# Run this if you've already built and want to re-view test output
# -----------------------------------------
show-test-results:
	@echo "[Test] Showing existing test results from last CTest run..."
	cd build && ctest --output-on-failure

# -----------------------------------------
# Generate coverage report using gcovr
# Assumes tests and code were built with --coverage flags
# -----------------------------------------
coverage: build
	@echo "[Coverage] Building TestExecutable..."
	cd build && cmake --build . --target TestExecutable

	@echo "[Coverage] Running tests sequentially for clean coverage..."
	cd build && ctest --output-on-failure --schedule-random=OFF --parallel 1

	@echo "[Coverage] Generating coverage reports in build/coverage/..."
	cd build && mkdir -p coverage
	cd build && gcovr -r .. --html --html-details -o coverage/index.html
	cd build && gcovr -r .. --xml -o coverage/coverage.xml
	cd build && gcovr -r .. --txt -o coverage/summary.txt

	@echo "[Coverage] ✅ Done! Open build/coverage/index.html to view the HTML report."
