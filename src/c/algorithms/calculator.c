#include "data-structures/stack.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Implement a simple calculator which can
 * evaluate a fully parenthesised and valid
 * arithmetic expression, like "(1 - (2 - 3))".
 * - all args are single digit ints
 * - support +,- operators
 *
 * Stretch goal:
 * - check for validity
 * - add more digits e.g., 42 (atoi instead of direct conversion, const char *
 * instead of char)
 * - add floats
 * - add more operators
 */

#define ERR_STACK_UNDERFLOW -1
#define ERR_INVALID_FUNC -2
#define ERR_INVALID_CHAR -3
#define ERR_STACK_LEFTOVER -4

// Function signature for +, -
typedef int (*IntBinOp)(int, int);

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int calculator(const char *expr) {
  struct stack s;
  init(&s, strlen(expr), sizeof(Variant));

  for (int i = 0; expr[i] != '\0'; i++) {
    // Ignore all '(', empty spaces
    // If it is a digit, push to the stack
    if (isdigit(expr[i])) {
      Variant ch = {.type = TYPE_CHAR, .data.c = expr[i]};
      push(&s, &ch);
      // If op, push corresponding function to the stack
    } else if (expr[i] == '+') {
      Variant fn = {.type = TYPE_INT_FUNC_PTR, .data.f = (void *)add};
      push(&s, &fn);
    } else if (expr[i] == '-') {
      Variant fn = {.type = TYPE_INT_FUNC_PTR, .data.f = (void *)sub};
      push(&s, &fn);
    } else if (expr[i] == ')') {
      // Pop last 3 values from the stack
      Variant arg1;
      Variant fn;
      Variant arg2;

      if (pop(&s, &arg1) != 0 || pop(&s, &fn) != 0 || pop(&s, &arg2 != 0)) {
        fprintf(stderr, "Stack underflow during evaluation.\n");
        freeStack(&s);
        // Idiomatic failure signal
        return ERR_STACK_UNDERFLOW;
      }

      if (fn.type != TYPE_INT_FUNC_PTR) {
        fprintf(stderr, "Invalid function type on stack.\n");
        freeStack(&s);
        return ERR_INVALID_FUNC;
      }

      // Cast to int directly
      int val1 = arg1.data.c - '0';
      int val2 = arg2.data.c - '0';
      // Cast and call
      IntBinOp op = (IntBinOp)fn.data.f;
      // Left-to-right
      int res = op(val2, val1);
      Variant result = {.type = TYPE_CHAR, .data.c = res + '0'};
      // Push the result back to the stack
      push(&s, &result);

    } else if (!isspace(expr[i]) && expr[i] != '(') {
      fprintf(stderr, "Invalid character: %c\n", expr[i]);
      freeStack(&s);
      return ERR_INVALID_CHAR;
    }
  }

  Variant out;
  if (pop(&s, &out) != 0) {
    fprintf(stderr, "No result on stack.\n");
    freeStack(&s);
    return -1;
  }
  if (!isEmpty(&s)) {
    fprintf(stderr, "Malformed expression: leftover stack entries.\n");
    freeStack(&s);
    return ERR_STACK_LEFTOVER;
  }

  freeStack(&s);

  return out.data.c - '0';
}

int main() { return 0; }