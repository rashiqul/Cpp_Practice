# ======================================================
# CMakeLists.txt for the SensorInheritance module
# This builds SensorInheritance.cpp into a standalone library
# that can be reused by both main() and test targets.
# ======================================================

# Build the SensorInheritance module as a static library
add_library(SensorInheritance SensorInheritance.cpp)

# Add the path to header files so others can include "SensorInheritance.h"
# Using PUBLIC makes this include path visible to any target that links to SensorInheritance
target_include_directories(SensorInheritance
    PUBLIC
    ${CMAKE_SOURCE_DIR}/code/inc
)
