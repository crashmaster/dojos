#include <algorithm>
#include <string>
#include <tuple>

#include <gtest/gtest.h>

#include "fizz_buzz.hpp"


typedef int input_t;
typedef std::string output_t;
typedef std::pair<input_t, output_t> test_value_t;
typedef std::vector<test_value_t> test_values_t;

test_values_t OUTPUT_EQUALS_INPUT_TEST_VALUES {
  {1, "1"},
  {2, "2"},
  {4, "4"},
  {7, "7"},
  {8, "8"},
  {11, "11"},
  {13, "13"},
  {14, "14"},
  {16, "16"},
  {17, "17"},
  {19, "19"},
  {22, "22"},
  {23, "23"},
  {26, "26"},
  {28, "28"},
  {29, "29"},
  {31, "31"},
  {32, "32"},
  {34, "34"},
};

// 3, 6, 9,
// 12, 18,
// 21, 24, 27,
// 33, 36

test_values_t negate_test_values(const test_values_t& test_values) {
  test_values_t negative_input_test_values;
  std::transform(
    test_values.begin(),
    test_values.end(),
    std::back_inserter(negative_input_test_values),
    [](const auto& test_value) -> test_value_t {
      return {
        -1 * test_value.first,
        std::to_string(-1 * std::stoi(test_value.second))
      };
    }
  );
  return negative_input_test_values;
}


void assert_fizz_buzz(const input_t input_number, const output_t& expected_output) {
  ASSERT_EQ(expected_output, fizz_buzz(input_number));
}


void verify_test_values(const test_values_t& test_values) {
  for (auto test_value: test_values) {
    input_t input_number;
    output_t expected_output;

    std::tie(input_number, expected_output) = test_value;
    assert_fizz_buzz(input_number, expected_output);
  }
}


TEST(fizz_buzz, positive_case_where_output_equals_input) {
  verify_test_values(OUTPUT_EQUALS_INPUT_TEST_VALUES);
}


TEST(fizz_buzz, negative_case_where_output_equals_input) {
  auto test_values = negate_test_values(OUTPUT_EQUALS_INPUT_TEST_VALUES);
  verify_test_values(test_values);
}


// TEST(fizz_buzz, where_input_results_in_fizz_output) {
//   std::vector<input_t, output_t> test_values { 3 };
// }


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
