add_executable(${EXECUTABLE_NAME} main.cpp)

# Link all required modules here
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
    FixedArray
    # Add other module libraries as needed
)
