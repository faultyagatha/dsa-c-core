#include "algorithms/merge_sort.h"

#include <assert.h>
#include <stdio.h>

int *merge_sort(int *arr, size_t len);

int main() {
  struct {
    int *arr;
    size_t len;
    int *expected;
  } tests[] = {// 1. Empty array
               {(int[]){}, 0, (int[]){}},

               // 2. Single element
               {(int[]){42}, 1, (int[]){42}},

               // 3. Already sorted
               {(int[]){1, 2, 3, 4, 5}, 5, (int[]){1, 2, 3, 4, 5}},

               // 4. Reverse sorted
               {(int[]){5, 4, 3, 2, 1}, 5, (int[]){1, 2, 3, 4, 5}},

               // 5. All identical elements
               {(int[]){7, 7, 7, 7}, 4, (int[]){7, 7, 7, 7}},

               // 6. Small random order
               {(int[]){3, 1, 2}, 3, (int[]){1, 2, 3}},

               // 7. Mixed positive & negative
               {(int[]){-1, 3, -2, 5, 0}, 5, (int[]){-2, -1, 0, 3, 5}},

               // 8. Larger random
               {(int[]){10, 1, 8, 3, 7, 2, 6, 4, 5, 9}, 10,
                (int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},

               // 9. Duplicates mixed in
               {(int[]){4, 2, 4, 1, 3, 2}, 6, (int[]){1, 2, 2, 3, 4, 4}},

               // 10. Negative numbers only
               {(int[]){-5, -10, -3, -1, -7}, 5, (int[]){-10, -7, -5, -3, -1}}};

  for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
    int *res = merge_sort(tests[i].arr, tests[i].len);
    printf("Test %d: input [", i + 1);
    for (size_t j = 0; j < tests[i].len; j++) {
      printf("%d", tests[i].arr[j]);
      if (j + 1 < tests[i].len)
        printf(", ");
    }
    printf("] => result [");
    for (size_t j = 0; j < tests[i].len; j++) {
      printf("%d", res[j]);
      if (j + 1 < tests[i].len)
        printf(", ");
    }
    printf("]\n");

    for (size_t j = 0; j < tests[i].len; j++) {
      assert(res[j] == tests[i].expected[j]);
    }
  }
  return 0;
}