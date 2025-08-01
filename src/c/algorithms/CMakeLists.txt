# src/c/algorithms/CMakeLists.txt

file(GLOB_RECURSE C_ALGO_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_library(c_algorithms STATIC ${C_ALGO_SOURCES})

target_include_directories(c_algorithms PUBLIC
    ${PROJECT_SOURCE_DIR}/include/c
)
