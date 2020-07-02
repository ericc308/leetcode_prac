#include "../hpp/str2int.hpp"

std::vector<int64_t> Str2Int::get_number(std::string input) {
  std::vector<int64_t> result;
  for (int ichar = 0; ichar < input.size(); ichar++) {
    std::string sub_number;
    int num_length = 0;
    int isnegative = -1;

    while (ichar < input.size()) {
      if (isNumber(input.at(ichar)) > 0) {
        if (num_length == 0 && ichar != 0) {
          char sign = input.at(ichar - 1);
          if (isMinus(sign) > 0) {
            isnegative = 1;
          } else {
            isnegative = -1;
          }
          sub_number.push_back(input.at(ichar));
          num_length++;
        } else {
          sub_number.push_back(input.at(ichar));
          num_length++;
        }
        ichar++;
      } else {
        break;
      }
    }
    if (sub_number.size() != 0) {
      if (isnegative > 0) {
        int64_t ans = str_to_int(sub_number);
        ans = 0 - ans;
        result.push_back(ans);
      } else {
        int64_t ans = str_to_int(sub_number);
        result.push_back(ans);
      }
    }
  }
  return result;
}

int Str2Int::get_number_or_warning(std::string input) {
  int64_t result = 0;
  int count = 0;
  int length = input.size();
  int isnegative = -1;
  int issign_repeated = 0;
  int isnegative_appeared = 0;
  int ispostive_appeared = 0;
  int first_0 = 0;
  std::string sub_string;
  std::vector<char> sign;
  for (int ichar = 0; ichar < length; ichar++) {
    // while ((input.at(ichar) == '0' && input.at(0) == '0')) { // when meet 0 first
    //   ichar++;
    // }
    char cur_char = input.at(ichar);
    if (isNumber(cur_char) > 0) {
      sub_string.push_back(cur_char);
    } else {
      if (isMinus(cur_char) > 0) {
        sign.push_back('-');
      } else {
        if (cur_char == ' ' || cur_char == '+') { // when ' ' , '+' and '0' appear at first.
          if (cur_char == '+') {
            sign.push_back('+');
          }
          // bypass since blank.
        } else {
          // first word is non number, break the loop.
          ichar = length;
        }
      }
    }
  }

  int length_of_sub = sub_string.size();
  // std::cout << "sub string :" << sub_string << std::endl;
  if (length_of_sub > 0) {
    // remove 0s at front of number
    sub_string = remove_front_zero(sub_string);
  }
  // std::cout << "sub string :" << sub_string << std::endl;
  if (sign.size() > 1) {
    sub_string = "";
    length_of_sub = 0;
  } else {
    if (sign.size() != 0) {
      if (sign.at(0) == '-') {
        isnegative = 1;
      }
    }
  }

  if (length_of_sub > 0) {
    // check if overflow?
    if (islargermax(sub_string) >= 0) {
      if (isnegative > 0) {
        result = INT32_MIN;
      } else {
        result = INT32_MAX;
      }
    } else {
      result = str_to_int(sub_string);
      if (isnegative > 0) {
        result = 0 - result;
      }
    }
  }
  return result;
}
