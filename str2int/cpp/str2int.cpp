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