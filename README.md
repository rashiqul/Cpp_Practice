# Cpp_Practice

This repository contains modular C++ practice projects primarily focused on embedded systems development. It is structured to support clean organization, test-driven development, and code coverage analysis using modern tooling.

---

## 📁 Repository Structure
```text
Cpp_Practice/
├── code/
│ ├── inc/ # Header files (.h)
│ └── src/ # Source files (.cpp)
├── test/ # Unit tests using GoogleTest/GoogleMock
├── build/ # CMake-generated build artifacts and coverage reports
└── Makefile # Simplified interface for common tasks
```
---

## 🛠️ Build System

This project uses **CMake** for build configuration and dependency management. It supports modular builds and integrates with common testing and coverage tools.

---

## ✅ Build and Test Instructions

The following `make` commands are available:

- `make clean` — Remove build artifacts and coverage files.
- `make build` — Configure and build all source files and test targets.
- `make run-tests` — Run all unit tests using GoogleTest.
- `make coverage` — Generate coverage reports in `build/coverage/index.html`.

> 💡 Prerequisites: Ensure `cmake`, `make`, `gcovr`, and a C++ compiler (e.g., `g++` or `clang++`) are installed.

---

## 🧪 Tools and Frameworks

- **CMake** — Cross-platform build system.
- **GoogleTest / GoogleMock** — Unit testing and mocking.
- **gcovr** — Generates HTML code coverage reports.
- **GCC / Clang** — Supported C++ compilers.

---

## 📊 Code Coverage

After running `make coverage`, open the following file in your browser to view annotated source code coverage:

build/coverage/index.html

yaml
Copy
Edit

---

## 🔧 Notes

- All modules are written in standard C++17.
- The project favors clarity, modularity, and testability to support embedded software development patterns