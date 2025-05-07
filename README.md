# Cpp_Practice

This repository contains C++ practice projects primarily targeted for embedded systems development. The structure and tools used in this repository are designed to facilitate efficient development, testing, and coverage analysis.

## Repository Structure

- **Source Code**: Located in `code/src/`, this directory contains the implementation files (`.cpp`).
- **Header Files**: Located in `code/inc/`, this directory contains the header files (`.h`).
- **Unit Tests**: Located in `test/`, this directory contains unit tests utilizing the GoogleTest and GoogleMock frameworks.
- **Build System**: The repository uses CMake as the build system.
- **Coverage Reports**: Coverage reports are generated using `gcovr` and can be found in `build/coverage/`. The main report is available in `index.html`.

## Build and Test Instructions

The following `make` commands are available:

- `make clean`: Clears the build directory.
- `make build`: Builds the source code and unit test code.
- `make run-tests`: Builds, compiles, and runs the unit test code.
- `make coverage`: Generates coverage reports inside `build/coverage/`. Open `index.html` to view the report.

## Tools and Frameworks

- **GoogleTest/GoogleMock**: Used for unit testing.
- **gcovr**: Used for generating code coverage reports.

This repository is structured to support best practices in embedded systems development and testing.