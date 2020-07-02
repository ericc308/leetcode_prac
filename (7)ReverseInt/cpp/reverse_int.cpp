#include "../hpp/reverse_int.hpp"

int ReverseInt::reverse(int input) {
  std::string input_str = std::to_string(input);
  std::string result;
  int result_num = 0;
  int isnegative = 0;
  if (input_str.at(0) == '-') {
    isnegative = 1;
    input_str.assign(input_str.begin() + 1, input_str.end());
    int length = input_str.size();
    for (int ichar = 0; ichar < length; ichar++) {
      result.push_back(input_str.at(length - ichar - 1));
    }
    if (islessmin(result) > 0) {
      result_num = 0;
    } else {
      result_num = 0 - atoi(result.c_str());
    }
  } else {
    int length = input_str.size();
    for (int ichar = 0; ichar < length; ichar++) {
      result.push_back(input_str.at(length - ichar - 1));
    }
    if (islargermax(result) > 0) {
      result_num = 0;
    } else {
      result_num = atoi(result.c_str());
    }
  }
  return result_num;
}

int ReverseInt::islargermax(std::string input) {
  int re = 0;
  int length = input.size();
  std::string max = "2147483648";

  if (length < 10) {
    std::string extension;
    for (int i = 0; i < 10 - length; i++) {
      extension.push_back('0');
    }
    extension.insert(extension.end(), input.begin(), input.end());
    // std::cout << input << std::endl;
    re = extension.compare(max);
  } else if (length > 10) {
    // std::cout << input << std::endl;
    re = 1;
  } else {
    // std::cout << input << std::endl;
    re = input.compare(max);
  }
  return re;
}

int ReverseInt::islessmin(std::string input) {
  int re = 0;
  int length = input.size();
  std::string min = "2147483647";

  if (length < 10) {
    std::string extension;
    for (int i = 0; i < 10 - length; i++) {
      extension.push_back('0');
    }
    extension.insert(extension.end(), input.begin(), input.end());
    // std::cout << input << std::endl;
    re = extension.compare(min);
  } else if (length > 10) {
    // std::cout << input << std::endl;
    re = 1;
  } else {
    // std::cout << input << std::endl;
    re = input.compare(min);
  }
  return re;
}