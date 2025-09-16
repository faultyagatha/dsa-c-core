// include/cpp/algorithms/fast_exp.hpp
#pragma once
#include <cstdlib>

int naiveExponent(int n, size_t exp);

int fastExponentRecursive(int n, size_t exp);

int fastExponentIterative(int n, size_t exp);