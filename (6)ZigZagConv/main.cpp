#include "hpp/zig_zag.hpp"

int main() {
  std::cout << " ZigZag :\n";
  ZigZag ZZ;
  std::string test1 = "PAYPALISHIRING";
  std::string ans1 = "PAHNAPLSIIGYIR";
  std::string ans2 = "PINALSIGYAHRPI";
  // std::string test1 = "ABCDEFGHIJK";
  // std::string ans1 = "PAHNAPLSIIGYIR";
  int test1_num = 3;
  int test2_num = 4;
  ZZ.convert(test1, test1_num);
  ZZ.convert(test1, test2_num);
  ZZ.convert("A", 1);
  ZZ.convert("ABCDE", 4);
  
  return 0;
}