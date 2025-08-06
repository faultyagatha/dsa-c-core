# tests/c/CMakeLists.txt

file(GLOB_RECURSE C_TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

# Loop over each test file and make a separate executable
foreach(test_file ${C_TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)
    
    add_executable(${test_name} ${test_file})
    
    target_include_directories(${test_name} PRIVATE
        ${PROJECT_SOURCE_DIR}/include/c
    )

    target_link_libraries(${test_name}
        c_data_structures  # link your C data structure library here, if any
        c_algorithms       # link your C algorithm library here, if any
    )

    # Register each test with CTest
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
