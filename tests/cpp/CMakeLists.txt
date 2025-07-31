# tests/cpp/CMakeLists.txt

# Recursively collect all .cpp test files in this directory
file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Create the test executable
add_executable(run_tests ${TEST_SOURCES})

# Link with your core libraries
target_link_libraries(run_tests
    PRIVATE
        data_structures
        algorithms
)

# Add include paths if needed (e.g., for test helpers or headers)
target_include_directories(run_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/cpp
)

# Optional: add to CTest to use it later
enable_testing()
add_test(NAME AllTests COMMAND run_tests)
