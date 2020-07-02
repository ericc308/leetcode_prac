#include "hpp/palindormic_num.hpp"
#include <ctime>

int main() {
  std::cout << " Palindormic_num  :\n";
  int input = 32;
  clock_t time_st, time_en;
  PalindromicNum PN;
  std::cout << " Input : " << input << std::endl;
  time_st = clock();
  std::cout << " Answer : " << PN.isPalindrome(input) << std::endl;
  time_en = clock();
  std::cout << " Programming time : "
            << double((double(time_en) - double(time_st)) / CLOCKS_PER_SEC *
                      1000)
            << std::endl;
  input = 232;
  std::cout << " Input : " << input << std::endl;
  time_st = clock();
  std::cout << " Answer : " << PN.isPalindrome(input) << std::endl;
  time_en = clock();
  std::cout << " Programming time : "
            << double((double(time_en) - double(time_st)) / CLOCKS_PER_SEC *
                      1000)
            << std::endl;
  return 0;
}