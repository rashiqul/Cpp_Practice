# Use the latest version of CMake
cmake_minimum_required(VERSION 3.22)

# Set the project name, version, and languages
project(CppProjectTeample VERSION 1.0.0 LANGUAGES C CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Set library and executable variables
set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME Library)

# Conditional build options
option(COMPILE_EXECUTABLE "Compile the executable" ON)

# Add the code directory
add_subdirectory(code)

# Add the main directory
if (COMPILE_EXECUTABLE)
    add_subdirectory(main)
else()
    message(STATUS "Skipping the main directory")
endif()