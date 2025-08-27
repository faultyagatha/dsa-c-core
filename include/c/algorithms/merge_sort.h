#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stddef.h> // for size_t

// Sorts an array of integers.
// Returns a newly allocated sorted array, or NULL on error.
// Caller is responsible for freeing the result.
int *merge_sort(int *arr, size_t len);

#endif // MERGE_SORT