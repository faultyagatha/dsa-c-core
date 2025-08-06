#ifndef CALCULATOR_H
#define CALCULATOR_H

// Error codes
#define ERR_STACK_UNDERFLOW -1
#define ERR_INVALID_FUNC -2
#define ERR_INVALID_CHAR -3
#define ERR_STACK_LEFTOVER -4

// Evaluate a fully-parenthesized arithmetic expression.
// Supports + and - with single-digit operands.
// Returns result or error code (< 0)
int calculator(const char *expr);

#endif // CALCULATOR_H