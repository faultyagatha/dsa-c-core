#include "algorithms/merge_sort.h"

#include <stdlib.h>
#include <string.h> // for memcpy

static void merge(int *arr, int *left, size_t left_len, int *right,
                  size_t right_len) {
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;

  while (i < left_len && j < right_len) {
    if (left[i] < right[j]) {
      arr[k] = left[i];
      i++;
      k++;
    } else if (left[i] > right[j]) {
      arr[k] = right[j];
      j++;
      k++;
    } else {
      // Found duplicate --> add both
      arr[k] = left[i];
      i++;
      k++;
      arr[k] = right[j];
      j++;
      k++;
    }
  }

  // Copy the rest
  while (i < left_len) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < right_len) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

int *merge_sort(int *arr, size_t len) {
  if (len <= 1) {
    // Already sorted
    return arr;
  }
  // Divide into left and right
  size_t mid = len / 2;

  // Allocate and copy left half
  int *left = malloc(mid * sizeof(int));
  if (!left)
    exit(EXIT_FAILURE);
  memcpy(left, arr, mid * sizeof(int));

  // Allocate and copy right half
  int *right = malloc((len - mid) * sizeof(int));
  if (!right)
    exit(EXIT_FAILURE);
  memcpy(right, arr + mid, (len - mid) * sizeof(int));

  // Recursively divide halves
  merge_sort(left, mid);
  merge_sort(right, len - mid);

  // Merge directly into arr
  merge(arr, left, mid, right, len - mid);

  free(left);
  free(right);

  return arr;
}