cmake_minimum_required(VERSION 3.28.2)
project(dsa-c-core VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories globally or per target in subdirs
include_directories(
    ${PROJECT_SOURCE_DIR}/include/cpp
    ${PROJECT_SOURCE_DIR}/include/c
)

# Add source trees (each has its own CMakeLists.txt)
add_subdirectory(src/cpp/algorithms)
add_subdirectory(src/cpp/data-structures)
# add_subdirectory(tests/cpp/algorithms)
# add_subdirectory(tests/cpp/data-structures)


