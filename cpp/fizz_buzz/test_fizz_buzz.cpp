#include "test_fizz_buzz_helper.hpp"


TEST(fizz_buzz, positive_case_where_output_equals_input) {
  verify_test_values(TEST_VALUES_WHERE_OUTPUT_EQUALS_INPUT);
}


TEST(fizz_buzz, negative_case_where_output_equals_input) {
  auto test_values = negate_test_values(TEST_VALUES_WHERE_OUTPUT_EQUALS_INPUT);
  verify_test_values(test_values);
}


TEST(fizz_buzz, where_input_results_in_fizz_output) {
  verify_test_values(TEST_VALUES_WHERE_INPUT_RESULTS_IN_FIZZ);
}


TEST(fizz_buzz, where_input_results_in_buzz_output) {
  verify_test_values(TEST_VALUES_WHERE_INPUT_RESULTS_IN_BUZZ);
}


TEST(fizz_buzz, where_input_results_in_fizz_buzz_output) {
  verify_test_values(TEST_VALUES_WHERE_INPUT_RESULTS_IN_FIZZ_BUZZ);
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
