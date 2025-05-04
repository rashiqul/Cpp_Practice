# ======================================================
# CMakeLists.txt for code/src/
# This file automatically adds all subdirectories
# ======================================================

# Find all immediate child entries (files or dirs) under code/src/
# Loop over only the directories
file(GLOB CHILD_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Loop through each child
foreach(subdir ${CHILD_DIRS})

    # Check if the entry is a directory (to exclude any stray files)
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}")

        # Add it as a subdirectory to be built (assumes each has its own CMakeLists.txt)
        add_subdirectory(${subdir})

    endif()
endforeach()
