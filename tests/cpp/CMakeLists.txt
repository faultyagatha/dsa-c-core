# tests/cpp/CMakeLists.txt

# Recursively collect all .cpp test files in this directory
file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

enable_testing()

# Create the test executable
add_executable(run_tests ${TEST_SOURCES})

# Link with the core libraries
target_link_libraries(run_tests
    PRIVATE
        data_structures
        algorithms
        GTest::gtest_main
)

# Add include paths if needed (e.g., for test helpers or headers)
target_include_directories(run_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/cpp
)

# Register with CTest
include(GoogleTest)
gtest_discover_tests(run_tests)

