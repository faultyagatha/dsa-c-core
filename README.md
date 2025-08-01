# Data Structures & Algorithms in C and C++

This repository contains implementations of commonly used **data structures** and **algorithms** in both **C** and **C++**. The goal is to provide clean, well-documented, and efficient code for educational purposes, interview preparation, and performance benchmarks.

## Repository Structure

dsa-c-core/
│
├── README.md
├── LICENSE
│
├── include/                    # Header files (to share declarations if any)
│   ├── c/
│   └── cpp/
│
├── src/                        # Source code
│   ├── c/
│   │   ├── data_structures/
│   │   │   ├── list.c
│   │   │   ├── dynamic_array.c
│   │   │   ├── matrix.c
│   │   │   ├── tree.c
│   │   │   └── ...
│   │   └── algorithms/
│   │       ├── sort.c
│   │       ├── search.c
│   │       ├── graph_algorithms.c
│   │       └── ...
│   │
│   └── cpp/
│       ├── data_structures/
│       │   ├── List.cpp
│       │   ├── DynamicArray.cpp
│       │   ├── Matrix.cpp
│       │   ├── Tree.cpp
│       │   └── ...
│       └── algorithms/
│           ├── Sort.cpp
│           ├── Search.cpp
│           ├── GraphAlgorithms.cpp
│           └── ...
│
├── tests/                      # Test files
│   ├── c/
│   └── cpp/
│
├── build/                      # Build outputs
│
├── CMakeLists.txt              # Build configuration
│
└── docs/                       # Optional documentation

## CMake Structure

| Path                         | CMake Target      | Type     | Description                           |
| ---------------------------- | ----------------- | -------- | ------------------------------------- |
| `src/cpp/data-structures/`   | `data_structures` | `STATIC` | Core list, tree, array, etc.          |
| `src/cpp/algorithms/`        | `algorithms`      | `STATIC` | Sort, search, graph algorithms        |
| `tests/cpp/`                 | `run_tests`       | `EXEC`   | Runs unit tests using above libraries |
| `benchmarks/cpp/` (optional) | `run_benchmarks`  | `EXEC`   | Runs performance benchmarks           |
| `examples/cpp/` (optional)   | `demo_main`       | `EXEC`   | Shows how to use a data structure     |


TODO: 
- Tagging each algorithm (e.g., O(n log n), Divide and Conquer) in comments or documentation.
- Benchmarking folder: Add timing and performance comparisons.
- Visualizations (optional)

## How to Run

```shell
# ----- cpp
# Build everything (default)
cmake -B build
cmake --build build

# Only build C++ benchmarks
cmake -DENABLE_C_BENCHMARKS=OFF -DENABLE_CPP_BENCHMARKS=ON -B build
cmake --build build

# Disable all benchmarks
cmake -DENABLE_C_BENCHMARKS=OFF -DENABLE_CPP_BENCHMARKS=OFF -B build
cmake --build build

# Run tests
./build/tests/cpp/run_tests

# ----- c
# Build everything (default)
cmake -B build
cmake --build build

# disable benchmarks
cmake -DENABLE_C_BENCHMARKS=OFF -B build
cmake --build build

# Run tests
./build/tests/c/run_c_tests
```
