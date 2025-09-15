#include "algorithms/merge_sort_rotations.hpp"

// O(n log n) comparisons
void mergeSortRotations(std::vector<int> &data, size_t low, size_t high) {
  if (high - low <= 1) {
    return;
  }
  size_t mid = low + (high - low) / 2;
  mergeSortRotations(data, low, mid);
  mergeSortRotations(data, mid, high);
  std::inplace_merge(data.begin() + low, data.begin() + mid,
                     data.begin() + high);
}

// Merge two adjacent sorted subarrays inside a single vector
// by rotating elements instead of copying them (std::rotate)
// Note:
// - the merging step is more expensive (rotations and shifting
// are costlier than appending to a buffer)
// - cache locality and the cost of element rotations might
// make it slower than the "extra buffer" variant in practice.

namespace {
void merge(std::vector<int> &data, size_t low, size_t mid, size_t high) {
  size_t i = low;
  size_t j = mid;
  while (i < j && j < high) {
    if (data[i] <= data[j]) {
      // Do nothing
      i++;
    } else if (data[i] > data[j]) {
      // Rotate the first element of the right half into position i,
      // shifting [i, j) one step to the right.
      std::rotate(data.begin() + i, data.begin() + j, data.begin() + j + 1);
      j++;
      i++;
    }
  }
}
} // namespace
