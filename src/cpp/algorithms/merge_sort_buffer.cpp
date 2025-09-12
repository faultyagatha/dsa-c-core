// merge_sort.cpp
#include "algorithms/merge_sort_buffer.hpp"

// Memory-hungry and cache-unfriendly merge sort
// that uses additional buffers
// O(n log n) time and space
// Anonymous namespace = internal linkage for everything inside
namespace {
static std::vector<int> merge(const std::vector<int> &left,
                              const std::vector<int> &right) {
  std::vector<int> res;
  size_t lenLeft = left.size();
  size_t lenRight = right.size();
  res.reserve(lenLeft + lenRight);
  size_t i = 0;
  size_t j = 0;
  while (i < lenLeft && j < lenRight) {
    // Compare and merge
    if (left[i] < right[j]) {
      res.push_back(left[i]);
      i++;
    } else if (left[i] > right[j]) {
      res.push_back(right[j]);
      j++;
    } else {
      // Equal --> push both
      res.push_back(left[i]);
      res.push_back(right[j]);
      i++;
      j++;
    }
  }
  // Check the rest and append
  while (i < lenLeft) {
    res.push_back(left[i]);
    i++;
  }

  while (j < lenRight) {
    res.push_back(right[j]);
    j++;
  }

  return res;
}
} // namespace

std::vector<int> mergeSortBuffer(const std::vector<int> &data) {
  size_t len = data.size();
  // Base case
  if (len <= 1) {
    return data;
  }

  size_t mid = len / 2;
  // Prepare a left-side vector
  std::vector<int> l(data.begin(), data.begin() + mid);
  // Recursively divide until based case is true
  std::vector<int> left = mergeSortBuffer(l);

  // Prepare a right-side vector
  std::vector<int> r(data.begin() + mid, data.end());
  // Recursively divide until based case is true
  std::vector<int> right = mergeSortBuffer(r);

  // Recursively merge
  return merge(left, right);
}