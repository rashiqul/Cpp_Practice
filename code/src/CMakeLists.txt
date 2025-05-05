# =========================================
# CMakeLists.txt for code/src/
# Gathers all .cpp files recursively
# =========================================

# Recursively collect all .cpp files under code/src/
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Make the list available to parent CMakeLists
set(PROJECT_SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)
