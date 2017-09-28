#include <stdio.h>


void fizz_buzz(char* output_buffer, const int number) {
  if ((number % 15) == 0) {
    sprintf(output_buffer, "fizz-buzz");
  }
  else if ((number % 3) == 0) {
    sprintf(output_buffer, "fizz");
  }
  else if ((number % 5) == 0) {
    sprintf(output_buffer, "buzz");
  }
  else {
    sprintf(output_buffer, "%d", number);
  }
}
