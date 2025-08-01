# tests/c/CMakeLists.txt

file(GLOB_RECURSE C_TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

add_executable(run_c_tests ${C_TEST_SOURCES})

target_link_libraries(run_c_tests
    PRIVATE
        c_data_structures
        c_algorithms
)

target_include_directories(run_c_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include/c
)

enable_testing()
add_test(NAME CTests COMMAND run_c_tests)
