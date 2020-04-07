#include "hpp/str2int.hpp"

int main() {
  Str2Int si;
  std::cout << " str to int:\n";
  // Test str_to_int
  std::cout << "Test 1: \n";
  std::string input = "-42";
  int64_t ans = si.str_to_int(input);
  if (ans == -42) {
    std::cout << "str_to_int('-42') \033[1;32mPASS!!\033[0m\n";
  } else {
    std::cout << "str_to_int('-42') \033[1;31mFAIL!!\033[0m\n";
  }
  std::cout << " Input :" << input << std::endl;
  std::cout << " Ans :" << ans << std::endl;
  // Test isNumber()
  std::cout << "Test 2-1: \n";
  char intb = 'a';
  if (si.isNumber(intb) > 0) {
    std::cout << "isNumber('a') \033[1;31mFAIL!!\033[0m\n";
  } else {
    std::cout << "isNumber('a') \033[1;32mPASS!!\033[0m\n";
  }
  std::cout << "Test 2-2: \n";
  intb = '5';
  if (si.isNumber(intb) < 0) {
    std::cout << "isNumber('5') \033[1;31mFAIL!!\033[0m\n";
  } else {
    std::cout << "isNumber('5') \033[1;32mPASS!!\033[0m\n";
  }
  // Test minus
  std::cout << "Test 3: \n";
  char minu = '-';
  if (si.isMinus(minu) > 0) {
    std::cout << "isMinus('-') \033[1;32mPASS!!\033[0m\n";
  } else {
    std::cout << "isMinus('-') \033[1;31mFAIL!!\033[0m\n";
  }
  std::string str_combine = "abc 56 cd ee 55-45";
  std::vector<int64_t> res = si.get_number(str_combine);
  std::vector<int64_t> ansnum{56, 55, -45};
  std::cerr << "Test 4: \n";
  for (int idata = 0; idata < res.size(); idata++) {
    if (ansnum[idata] == res[idata]) {
      std::cout << "\033[1;32mPASS!!\033[0m : getNumber() " << ansnum[idata] << " in " << str_combine << "\n";
    } else {
      std::cout << "\033[1;31mFAIL!!\033[0m : getNumber() is :" << res[idata] << ", it should be" << ansnum[idata] << " in " << str_combine << "\n";
    }
  }
  int64_t res_2 = si.get_number_or_warning(str_combine);
  if (res_2 == 0) {
    std::cout << "\033[1;32mPASS!!\033[0m : get_number_or_warning() " << 0 << " in " << str_combine << "\n";
  } else {
    std::cout << "\033[1;31mFAIL!!\033[0m : get_number_or_warning() is :" << res_2 << ", it should be" << 0 << " in " << str_combine << "\n";
  }
  str_combine = "-456";
  int64_t res_3 = si.get_number_or_warning(str_combine);
  if (res_3 == -456) {
    std::cout << "\033[1;32mPASS!!\033[0m : get_number_or_warning() " << -456 << " in " << str_combine << "\n";
  } else {
    std::cout << "\033[1;31mFAIL!!\033[0m : get_number_or_warning() is : " << res_3 << ", it should be" << -456 << " in " << str_combine << "\n";
  }
  str_combine = "  0456";
  int64_t res_4 = si.get_number_or_warning(str_combine);
  if (res_4 == 456) {
    std::cout << "\033[1;32mPASS!!\033[0m : get_number_or_warning() " << 456 << " in " << str_combine << "\n";
  } else {
    std::cout << "\033[1;31mFAIL!!\033[0m : get_number_or_warning() is : " << res_4 << ", it should be" << 456 << " in " << str_combine << "\n";
  }

  str_combine = "-912834723322";
  int64_t res_5 = si.get_number_or_warning(str_combine);
  if (res_5 == INT32_MIN) {
    std::cout << "\033[1;32mPASS!!\033[0m : get_number_or_warning() " << INT32_MIN << " in " << str_combine << "\n";
  } else {
    std::cout << "\033[1;31mFAIL!!\033[0m : get_number_or_warning() is : " << res_5 << ", it should be" << INT32_MIN << " in " << str_combine << "\n";
  }

  str_combine = " 0000000000012345678";
  int64_t res_6 = si.get_number_or_warning(str_combine);
  if (res_6 == 12345678) {
    std::cout << "\033[1;32mPASS!!\033[0m : get_number_or_warning() " << 12345678 << " in " << str_combine << "\n";
  } else {
    std::cout << "\033[1;31mFAIL!!\033[0m : get_number_or_warning() is : " << res_6 << ", it should be" << 12345678 << " in " << str_combine << "\n";
  }
}