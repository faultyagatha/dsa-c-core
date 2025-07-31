# src/cpp/algorithms/CMakeLists.txt

# Collect all source files in this directory
file(GLOB_RECURSE ALGO_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# Create a static library target
add_library(algorithms STATIC ${ALGO_SOURCES})

# Add include directory if needed for headers
target_include_directories(algorithms PUBLIC
    ${PROJECT_SOURCE_DIR}/include/cpp
)