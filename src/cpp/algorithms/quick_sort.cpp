#include "quick_sort.hpp"

// - Pick the pivot value (typically, first elem)
// - Move everything what is > pivot to the left side
// and what is < pivot to the right in a linear fashion
// - Swap pivot idx (0) with the idx of where pivot should go
// - Recursively apply the same approach to the 2 subarrays (left and right)
// in range [low, high): using low inclusive and high exclusive is
// a nice idiom (matches std::vector iterators).

void quickSort(std::vector<int> &data, size_t low, size_t high) {
  if (high - low <= 1)
    return;

  size_t pivotIdx = low;

  for (size_t i = low + 1; i < high; i++) {
    if (data[low] > data[i]) {
      pivotIdx++;
      // Move elements smaller than the pivot to the left side
      std::swap(data[pivotIdx], data[i]);
    }
  }
  // Swap value at low with the value at pivotIdx
  // The array is partitioned: [low, pivotIdx) < pivot ≤ [pivotIdx+1, high)
  std::swap(data[low], data[pivotIdx]);

  // Left subarray [low, pivotIdx)
  quickSort(data, low, pivotIdx);
  // Right subarray [pivotIdx+1, high)
  quickSort(data, pivotIdx + 1, high);
}