#include <assert.h>

#include <gtest/gtest.h>

#include "%%dojo_name%%.hpp"


TEST(%%dojo_name%%, write_the_first_test_case_here) {
  ASSERT_EQ(1, 1);
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
