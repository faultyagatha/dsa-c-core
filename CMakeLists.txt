cmake_minimum_required(VERSION 3.28.2)
project(dsa-c-core VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional toggles
option(ENABLE_C_BENCHMARKS "Build C benchmarks" ON)
option(ENABLE_CPP_BENCHMARKS "Build C++ benchmarks" ON)

# Add include directories globally or per target in subdirs
include_directories(
    ${PROJECT_SOURCE_DIR}/include/cpp
    ${PROJECT_SOURCE_DIR}/include/c
)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Prevent GoogleTest from forcing its own tests
set(BUILD_GTEST ON)
set(BUILD_GMOCK OFF)
FetchContent_MakeAvailable(googletest)


# C++ source trees (each has its own CMakeLists.txt)
add_subdirectory(src/cpp/algorithms)
add_subdirectory(src/cpp/data-structures)
add_subdirectory(tests/cpp)

# C source trees
add_subdirectory(src/c/data-structures)
add_subdirectory(src/c/algorithms)
add_subdirectory(tests/c) 

# Optional benchmarks
if(ENABLE_C_BENCHMARKS)
    add_subdirectory(benchmarks/c)
endif()

if(ENABLE_CPP_BENCHMARKS)
    add_subdirectory(benchmarks/cpp)
endif()



