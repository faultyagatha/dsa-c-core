#include "data-structures/stack.h"
#include <assert.h>
#include <stdio.h>

int calculator(const char *expr);

int main() {
  struct {
    const char *expr;
    int expected;
  } tests[] = {
      {"(1+(2+3))", 6},     {"(1-(2-3))", 2},      {"((1+2)-(3-4))", 4},
      {"(9-(5+1))", 3},     {"(((1+2)+3)+4)", 10}, {"(9-((2+3)+1))", 3},
      {"((3+4)-(1+2))", 4}, {"(1+2)", 3},          {"(4-(1+2))", 1},
      {"((7-4)+(3+1))", 7},
  };

  for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
    int res = calculator(tests[i].expr);
    printf("Test %d: %s = %d\n", i + 1, tests[i].expr, res);

    assert(res == tests[i].expected);
  }
  return 0;
}