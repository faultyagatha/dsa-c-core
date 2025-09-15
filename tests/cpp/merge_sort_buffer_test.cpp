#include "algorithms/merge_sort_buffer.hpp"
#include <gtest/gtest.h>
#include <vector>

// Helper to check if vector is sorted
bool isSorted(const std::vector<int> &vec) {
  for (size_t i = 1; i < vec.size(); ++i) {
    if (vec[i - 1] > vec[i])
      return false;
  }
  return true;
}

// Test: empty input
TEST(MergeSortTest, EmptyVector) {
  std::vector<int> data;
  auto result = mergeSortBuffer(data);
  EXPECT_TRUE(result.empty());
}

// Test: single element
TEST(MergeSortTest, SingleElement) {
  std::vector<int> data = {42};
  auto result = mergeSortBuffer(data);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 42);
}

// Test: already sorted
TEST(MergeSortTest, AlreadySorted) {
  std::vector<int> data = {1, 2, 3, 4, 5};
  auto result = mergeSortBuffer(data);
  EXPECT_TRUE(isSorted(result));
  EXPECT_EQ(result, data); // content should match original
}

// Test: reverse sorted
TEST(MergeSortTest, ReverseSorted) {
  std::vector<int> data = {5, 4, 3, 2, 1};
  auto result = mergeSortBuffer(data);
  EXPECT_TRUE(isSorted(result));
}

// Test: random order
TEST(MergeSortTest, RandomOrder) {
  std::vector<int> data = {3, 1, 4, 5, 2};
  auto result = mergeSortBuffer(data);
  EXPECT_TRUE(isSorted(result));
}

// Test: duplicates
TEST(MergeSortTest, WithDuplicates) {
  std::vector<int> data = {2, 3, 2, 1, 3};
  auto result = mergeSortBuffer(data);
  EXPECT_TRUE(isSorted(result));
  EXPECT_EQ(result.size(), data.size());
}
