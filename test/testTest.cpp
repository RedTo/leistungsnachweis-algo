#include "gtest.h"
#include "../main/ClassToTest.cpp"

TEST(TEST_TEST, TestAndTest) {
  ASSERT_EQ(getTest(), 42);
}
