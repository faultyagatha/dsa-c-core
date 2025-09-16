#include "algorithms/fast_exp.hpp"

// Raise a number to the power of an integer n (linear time)
int naiveExponent(int n, size_t exp) {
  int res = 1;
  for (size_t i = 0; i < exp; i++) {
    res *= n;
  }
  return res;
}

// Raise a number to the power of an integer n O(log exp)
int fastExponentRecursive(int n, size_t exp) {
  if (exp == 0)
    return 1;
  if (exp % 2 == 1) {
    return n * fastExponentRecursive(n, exp - 1);
  }
  int res = fastExponentRecursive(n, exp / 2);
  return res * res;
}

int fastExponentIterative(int n, size_t exp) {
  int res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      res *= n;
      exp--;
    } else {
      n *= n;
      exp /= 2;
    }
  }
  return res;
}