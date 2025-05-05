# =========================================
# Makefile for C++ Modular Project with GTest + Coverage
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
	@echo "[Test] ✅ Done! Check the output above for test results."

# -----------------------------------------
# Generate coverage report using gcovr
# -----------------------------------------
coverage: build
	@echo "[Coverage] Building TestExecutable..."
	cd build && cmake --build . --target TestExecutable

	@echo "[Coverage] Running tests to collect coverage data..."
	./build/test/TestExecutable

	@echo "[Coverage] Generating coverage reports in build/coverage/..."
	cd build && mkdir -p coverage

# ---------------------------
# HTML Report
# ---------------------------
# Use root as project root, filter to include only code/src,
# and exclude test/ and googletest files
	cd build && gcovr -r .. \
	    --filter='code/src' \
	    --exclude='test' \
	    --exclude='.*googletest.*' \
	    --html --html-details -o coverage/index.html

# ---------------------------
# XML Report (CI Tools)
# ---------------------------
	cd build && gcovr -r .. \
	    --filter='code/src' \
	    --exclude='test' \
	    --exclude='.*googletest.*' \
	    --xml -o coverage/coverage.xml

# ---------------------------
# Text Summary Report
# ---------------------------
	cd build && gcovr -r .. \
	    --filter='code/src' \
	    --exclude='test' \
	    --exclude='.*googletest.*' \
	    --txt -o coverage/summary.txt

	@echo "[Coverage] ✅ Done! Open build/coverage/index.html to view the HTML report."
