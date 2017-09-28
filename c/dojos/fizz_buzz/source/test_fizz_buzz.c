#include <assert.h>
#include <string.h>

#include "fizz_buzz.h"


void assert_fizz_buzz(char* output_buffer, const char* expected_result, const int input_number) {
  fizz_buzz(output_buffer, input_number);
  assert(strcmp(expected_result, output_buffer) == 0);
}

struct test_data_entry {
  int input_number;
  char* expected_result;
};

void test_fizz_buzz() {
  struct test_data_entry test_data[] = {
    {1, "1"},
    {2, "2"},
    {3, "fizz"},
    {4, "4"},
    {5, "buzz"},
    {6, "fizz"},
    {10, "buzz"},
    {15, "fizz-buzz"},
  };

  for (size_t i=0; i < sizeof(test_data)/sizeof(test_data[0]); i++) {
    char output_buffer[256];
    assert_fizz_buzz(
      output_buffer,
      test_data[i].expected_result,
      test_data[i].input_number
    );
  }
}
