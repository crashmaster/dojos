#include <gtest/gtest.h>

#include "fizz_buzz.hpp"


TEST(fizz_buzz, input_is_zero) {
  ASSERT_EQ(0, fizz_buzz(0));
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
