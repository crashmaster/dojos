#include "fizz_buzz.hpp"


bool is_number_dividable_by(const int number, const int divider) {
  return number % divider == 0;
}


std::string fizz_buzz(const int number) {
  std::string result{""};
  if (is_number_dividable_by(number, 3)) {
    result.append({"Fizz"});
  }
  if (is_number_dividable_by(number, 5)) {
    result.append({"Buzz"});
  }
  if (result.empty()) {
    result.append(std::to_string(number));
  }
  return result;
}
