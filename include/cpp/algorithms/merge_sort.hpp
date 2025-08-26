// include/cpp/algorithms/merge_sort.hpp
#pragma once
#include <vector>

std::vector<int> mergeSort(const std::vector<int> &data);
std::vector<int> merge(const std::vector<int> &left,
                       const std::vector<int> &right);