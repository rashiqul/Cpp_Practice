# ======================================================
# CMakeLists.txt for the FixedArray module
# This builds FixedArray.cpp into a standalone library
# that can be reused by both main() and test targets.
# ======================================================

# Build the FixedArray module as a static library
add_library(FixedArray FixedArray.cpp)

# Add the path to header files so others can include "FixedArray.h"
# Using PUBLIC makes this include path visible to any target that links to FixedArray
target_include_directories(FixedArray
    PUBLIC
    ${CMAKE_SOURCE_DIR}/code/inc
    PRIVATE
    ${CMAKE_SOURCE_DIR}/code/inc
)
