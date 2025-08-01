# src/c/data-structures/CMakeLists.txt

file(GLOB_RECURSE C_DS_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(c_data_structures STATIC ${C_DS_SOURCES})

target_include_directories(c_data_structures PUBLIC
    ${PROJECT_SOURCE_DIR}/include/c
)
