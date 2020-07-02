#include "../hpp/palindormic_num.hpp"

bool PalindromicNum::isPalindrome(int input) {
  std::string input_str = std::to_string(input);
  std::string result;
  bool ispalin = true;
  if (input_str.at(0) == '-') {
      ispalin = false;
  } else {
    if (is_palindromic(input_str))
      ispalin = true;
    else
      ispalin = false;
  }
  return ispalin;
}
int PalindromicNum::is_palindromic(std::string input) {
  int length = input.size();
  int mid = length / 2;
  int is_palin = 1;
  for (int ichar = 0; ichar < mid; ichar++) {
    if (input.at(ichar) != input.at(length - ichar - 1)) {
      is_palin = 0;
      ichar = mid;
    }
  }
  return is_palin;
}
