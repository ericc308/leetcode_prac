#include "hpp/reverse_int.hpp"
#include <ctime>

int main() {
  clock_t time_st;
  clock_t time_en;
  std::cout << " reverse_int :\n";
  int in_num = -321;
  ReverseInt RI;
  std::cout << " Int Max: " << INT32_MAX << " , Int Min: " << INT32_MIN
            << std::endl;
  std::cout << " Input : " << in_num << std::endl;
  time_st = clock();
  std::cout << " Answer : " << RI.reverse(in_num) << std::endl;
  time_en = clock();
  std::cout << " Programming time : "
            << double((double(time_en) - double(time_st)) / CLOCKS_PER_SEC *
                      1000)
            << std::endl;
  in_num = 4567;
  std::cout << " Input : " << in_num << std::endl;
  time_st = clock();
  std::cout << " Answer : " << RI.reverse(in_num) << std::endl;
  time_en = clock();
  std::cout << " Programming time : "
            << double((double(time_en) - double(time_st)) / CLOCKS_PER_SEC *
                      1000)
            << std::endl;
}