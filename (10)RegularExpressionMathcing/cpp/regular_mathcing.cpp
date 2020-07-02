#include "../hpp/regular_mathcing.hpp"

bool RegularMathcing::isMatch(std::string str, std::string pattern) {

  std::vector<std::string> compare_list = get_sub_pattern(pattern);
  // for(int iist=0;iist<compare_list.size();iist++){
  //   std::cout<<"compare_list["<<iist<<"]:"<<compare_list[iist]<<std::endl;
  // }
  int reference_length = str.size();
  int index_of_checked_char = 0;
  int equal_final = 1;
  int dotstar = 0;

  for (int icompare = 0; icompare < compare_list.size(); icompare++) {
    // std::cout<<"compare_list["<<icompare<<"]:"<<compare_list[icompare]<<std::endl;
    if (compare_list[icompare].at(0) != '*') {
      int issame =
          isSubstringEqual(str, compare_list[icompare], index_of_checked_char,
                           compare_list[icompare].size());
      if (issame > 0) {
        index_of_checked_char =
            index_of_checked_char + compare_list[icompare].size();
      } else {
        icompare = compare_list.size();
        equal_final = 0;
      }
    } else {
      if (compare_list[icompare].at(1) == '.') {
        dotstar = 1;
      } else {
        if(index_of_checked_char < reference_length){
            int repeated_times = RepeatSubstringEqualStarTimes(
            str, compare_list[icompare], index_of_checked_char);
          index_of_checked_char = index_of_checked_char + repeated_times;
        }
      }
    }
  }

  if (index_of_checked_char < reference_length && dotstar == 0) {
    equal_final = 0;
  }
  return equal_final;
}

std::vector<std::string> RegularMathcing::get_sub_pattern(std::string input) {
  std::string sign;
  std::vector<std::string> sub_pattern_all;
  int length = input.size();
  std::string sub_pattern;
  for (int ichar = 0; ichar < length; ichar++) {
    if (input.at(ichar) != '*' && ichar != length - 1) {
      for (int isubchar = ichar; isubchar < length; isubchar++) {
        if (input.at(isubchar) != '*' && isubchar != length - 1) {
          sub_pattern.push_back(input.at(isubchar));
        } else {
          if (input.at(isubchar) == '*') {
            sub_pattern.pop_back();
            std::string star;
            star.push_back(input.at(isubchar));
            star.push_back(input.at(isubchar - 1));
            if (sub_pattern.empty()) {
              sub_pattern_all.push_back(star);
            } else {
              sub_pattern_all.push_back(sub_pattern);
              sub_pattern_all.push_back(star);
            }
            sub_pattern.clear();
            ichar = isubchar;
            isubchar = length;
          } else {
            sub_pattern.push_back(input.at(isubchar));
            sub_pattern_all.push_back(sub_pattern);
            sub_pattern.clear();
            ichar = isubchar;
            isubchar = length;
          }
        }
      }
    } else {
      sub_pattern.push_back(input.at(ichar));
      sub_pattern_all.push_back(sub_pattern);
    }
  }

  return sub_pattern_all;
}

int RegularMathcing::isSubstringEqual(std::string &input, std::string substr,
                                      int ibeg, int num) {
  // std::cout<<"compare_sub ="<<substr<<std::endl;
  // std::cout<<"ibeg:"<<ibeg<<", num:"<<num<<std::endl;
  int equal = 1;
  int max = input.size();
  for (int ichar = 0; ichar < num; ichar++) {
    if ((ibeg + ichar < max)) {
      if (substr.at(ichar) == '.') {
        // can be anything
        // std::cout<<"compare_sub is ="<<substr<<std::endl;
        // std::cout<<"num ="<<num<<std::endl;
      } else if ((input.at(ibeg + ichar) != substr.at(ichar))) {
        equal = 0;
        ichar = num;
      } else {
        // same;
      }

    } else {  // exceed origin str
      equal = 0;
      ichar = num;
    }
  }
  return equal;
}

int RegularMathcing::RepeatSubstringEqualStarTimes(std::string &input,
                                                   std::string substr,
                                                   int ibeg) {
  int repeat = 0;
  int max = input.size();
  if (input.at(ibeg) != substr.at(1)) {
    repeat = 0;
  } else {
    for (int ichar = ibeg; ichar < max; ichar++) {
      if (input.at(ichar) != substr.at(1)) {
        ichar = max;
      } else {
        repeat = repeat + 1;
      }
    }
  }
  return repeat;
}