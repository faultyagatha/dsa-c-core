#include "algorithms/merge_sort.h"

#include <stdlib.h>

int *merge_sort(int *arr) {
  // Check this, what if the arr is []!
  size_t len = sizeof(arr) / sizeof(arr[0]);
  if (len <= 1) {
    return arr;
  }
  // Divide into left and right
  size_t mid = len / 2;
  int *left;
  int *right;

  // Call merge_sort recursively on each side until 1 elem left
  // Call merge on each recursive call of merge_sort
  return arr;
}

int *merge(int *left, int *right) { return left; }