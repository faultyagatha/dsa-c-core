#include "data-structures/stack.h"

/**
 * Implement a simple calculator which can
 * evaluate a fully parenthesized and valid
 * arithmetic expression, like "(1 - (2 - 3))".
 * - all args are single digit ints
 * - support +,- operators
 *
 * Stretch goal:
 * - check for validity
 * - add more digits and optionally, floats
 * - add more operators
 */

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int calculator(const char *expr) {
  struct stack s;
  for (int i = 0; expr[i] != '\0'; i++) {
    // Ignore all '('
    // If it is a digit, push to the stack
    if (isdigit(expr[i])) {
      push(&s, expr[i]);
      // If op, push corresponding function to the stack
    } else if (expr[i] == '+' || expr[i] == '-') {
      push()
    } else if (expr[i] == ')') {
      // pop last 3 values from the stack and evaluate
      // push the result back to the stack
    } else {
      // ignore any other char
    }

    return pop(&s);
  }

  return 0;
}

int main() { return 0; }