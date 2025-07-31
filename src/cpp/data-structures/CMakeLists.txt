# src/cpp/data-structures/CMakeLists.txt

# Collect all source files in this directory
file(GLOB_RECURSE STREAM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# Create a static library target
add_library(data_structures STATIC ${STREAM_SOURCES})

# Add include directory if needed for headers
target_include_directories(data_structures PUBLIC
    ${PROJECT_SOURCE_DIR}/include/cpp
)
