#include "algorithms/fast_exp.hpp"
#include <gtest/gtest.h>

TEST(ExponentTest, ZeroExponent) {
  EXPECT_EQ(naiveExponent(5, 0), 1);
  EXPECT_EQ(fastExponentRecursive(5, 0), 1);
  EXPECT_EQ(fastExponentIterative(5, 0), 1);
  EXPECT_EQ(naiveExponent(0, 0), 1);
  EXPECT_EQ(fastExponentRecursive(0, 0), 1);
  EXPECT_EQ(fastExponentIterative(0, 0), 1);
}

TEST(ExponentTest, OneExponent) {
  EXPECT_EQ(naiveExponent(7, 1), 7);
  EXPECT_EQ(fastExponentRecursive(7, 1), 7);
  EXPECT_EQ(fastExponentIterative(7, 1), 7);
}

TEST(ExponentTest, SmallNumbers) {
  EXPECT_EQ(naiveExponent(2, 3), 8);
  EXPECT_EQ(fastExponentRecursive(2, 3), 8);
  EXPECT_EQ(fastExponentIterative(2, 3), 8);

  EXPECT_EQ(naiveExponent(3, 4), 81);
  EXPECT_EQ(fastExponentRecursive(3, 4), 81);
  EXPECT_EQ(fastExponentIterative(3, 4), 81);
}

TEST(ExponentTest, NegativeBase) {
  EXPECT_EQ(naiveExponent(-2, 3), -8);
  EXPECT_EQ(fastExponentRecursive(-2, 3), -8);
  EXPECT_EQ(fastExponentIterative(-2, 3), -8);

  EXPECT_EQ(naiveExponent(-2, 4), 16);
  EXPECT_EQ(fastExponentRecursive(-2, 4), 16);
  EXPECT_EQ(fastExponentIterative(-2, 4), 16);
}

TEST(ExponentTest, LargerExponent) {
  EXPECT_EQ(naiveExponent(2, 10), 1024);
  EXPECT_EQ(fastExponentRecursive(2, 10), 1024);
  EXPECT_EQ(fastExponentIterative(2, 10), 1024);

  EXPECT_EQ(naiveExponent(3, 6), 729);
  EXPECT_EQ(fastExponentRecursive(3, 6), 729);
  EXPECT_EQ(fastExponentIterative(3, 6), 729);
}

TEST(ExponentTest, ConsistencyCheck) {
  for (int base = -5; base <= 5; base++) {
    for (size_t exp = 0; exp <= 10; exp++) {
      EXPECT_EQ(naiveExponent(base, exp), fastExponentRecursive(base, exp));
      EXPECT_EQ(fastExponentRecursive(base, exp),
                fastExponentIterative(base, exp));
    }
  }
}
