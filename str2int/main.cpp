#include "hpp/str2int.hpp"

int main() {
  Str2Int si;
  std::cout << " str to int:\n";
  // Test str_to_int
  std::cout << "Test 1: \n";
  std::string input = "-42";
  int64_t ans = si.str_to_int(input);
  if (ans == -42) {
    std::cout << "str_to_int('-42') pass!\n";
  } else {
    std::cout << "str_to_int('-42') fail!!\n";
  }
  std::cout << " Input :" << input << std::endl;
  std::cout << " Ans :" << ans << std::endl;
  // Test isNumber()
  std::cout << "Test 2-1: \n";
  char intb = 'a';
  if (si.isNumber(intb) > 0) {
    std::cout << "isNumber('a') fail!\n";
  } else {
    std::cout << "isNumber('a') pass!\n";
  }
  std::cout << "Test 2-2: \n";
  intb = '5';
  if (si.isNumber(intb) < 0) {
    std::cout << "isNumber('5') fail!\n";
  } else {
    std::cout << "isNumber('5') pass!\n";
  }
  // Test minus
  std::cout << "Test 3: \n";
  char minu = '-';
  if (si.isMinus(minu) > 0) {
    std::cout << "isMinus('-') pass!!\n";
  } else {
    std::cout << "isMinus('-') fail!!\n";
  }

  std::vector<int64_t> res = si.get_number("abc 56 cd ee 55-45");
  for (int idata = 0; idata < res.size(); idata++) {
    std::cout << res[idata] << std::endl;
  }
}