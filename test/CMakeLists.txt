# =========================================
# CMakeLists.txt for test/ directory
# GoogleTest-only setup (no CTest)
# =========================================

cmake_minimum_required(VERSION 3.14)

# -----------------------------------------
# GoogleTest Download + Setup
# -----------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # MSVC-specific, safe to keep
FetchContent_MakeAvailable(googletest)

# -----------------------------------------
# Enable Code Coverage (only in Debug mode)
# -----------------------------------------
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "✅ Code coverage enabled for GCC/Clang in Debug mode")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 --coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    endif()
endif()

# -----------------------------------------
# Gather test sources (can be globbed or explicit)
# -----------------------------------------
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# -----------------------------------------
# Build test executable (linked with test sources)
# -----------------------------------------
add_executable(TestExecutable ${TEST_SOURCES})

# -----------------------------------------
# Include header paths from your main code
# -----------------------------------------
target_include_directories(TestExecutable
    PRIVATE ${CMAKE_SOURCE_DIR}/code/inc
)

# -----------------------------------------
# Link with GTest and your code modules
# -----------------------------------------
target_link_libraries(TestExecutable
    PRIVATE
    gtest
    gtest_main
    FixedArray
)

# Optional: Put test binary in a clean /test/ folder
set_target_properties(TestExecutable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
)
