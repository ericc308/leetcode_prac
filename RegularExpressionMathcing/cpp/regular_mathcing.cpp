#include "../hpp/regular_mathcing.hpp"

bool RegularMathcing::isMatch(std::string str, std::string pattern) {
  std::vector<std::string> parsing_pattern = get_sub_pattern(pattern);
  std::string sign = parsing_pattern[0];
  std::vector<std::string> sub_pattern;
  sub_pattern.assign(parsing_pattern.begin() + 1, parsing_pattern.end());
  if (sign.empty()) {
  }
}

std::vector<std::string> RegularMathcing::get_sub_pattern(std::string input) {
  std::string sign;
  std::vector<std::string> sub_pattern_all;
  int length = input.size();
  std::string sub_pattern;
  for (int ichar = 0; ichar < length; ichar++) {
    if (input.at(ichar) != '*' && input.at(ichar) != '.') {
      sub_pattern.push_back(input.at(ichar));
    } else {
      sign.push_back(input.at(ichar));
      sub_pattern_all.push_back(sub_pattern);
      sub_pattern.clear();
    }
  }
  if (sign.size() == 0) {
    sub_pattern_all.push_back(sub_pattern);
    sub_pattern_all.insert(sub_pattern_all.begin(), sign);
  } else {
    sub_pattern_all.insert(sub_pattern_all.begin(), sign);
  }
  return sub_pattern_all;
}

int RegularMathcing::isSubstringEqual(std::string &input, std::string substr,
                                      int ibeg, int num) {
  int equal = 1;
  int max = input.size();
  for (int ichar = 0; ichar < num; ichar++) {
    if ((ibeg + ichar < max)) {
      if ((input.at(ibeg + ichar) != substr.at(ichar))) {
        equal = 0;
        ichar = num;
      } else {
        // same;
      }
    } else {
      equal = 0;
      ichar = num;
    }
  }
  return equal;
}