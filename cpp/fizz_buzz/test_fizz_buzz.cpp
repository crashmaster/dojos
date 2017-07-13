#include "test_fizz_buzz_helper.hpp"


TEST(fizz_buzz, positive_case_where_output_equals_input) {
  ::verify_test_values(TEST_VALUES_FOR_OUTPUT_EQUALS_INPUT_CASE);
}


TEST(fizz_buzz, negative_case_where_output_equals_input) {
  auto test_values = negate_test_values(TEST_VALUES_FOR_OUTPUT_EQUALS_INPUT_CASE);
  verify_test_values(test_values);
}


// TEST(fizz_buzz, where_input_results_in_fizz_output) {
//   std::vector<input_t, output_t> test_values { 3 };
// }


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
