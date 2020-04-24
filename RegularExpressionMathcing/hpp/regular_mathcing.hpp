#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

class RegularMathcing {
public:
  bool isMatch(std::string str, std::string pattern);
  std::vector<std::string> get_sub_pattern(std::string input);
  int isSubstringEqual(std::string &input, std::string substr, int ibeg,
                       int num);
};