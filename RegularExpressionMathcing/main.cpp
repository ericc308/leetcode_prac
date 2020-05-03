#include "hpp/regular_mathcing.hpp"
#include <chrono>
#include <ctime>
int main() {
  // \033[shape of fonts;color of fonts;back ground of fonts
  RegularMathcing RM;

  std::cout << "\033[1;33;42mRegular Experession Mathcing\033[0m :\n";

  auto start = std::chrono::steady_clock::now();

  auto end = std::chrono::steady_clock::now();

  std::cout << "time elapsed : "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << " us" << std::endl;
  std::cout << "time elapsed : "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << " ms" << std::endl;

  std::string compare = "c*a*b";
  std::string Reference = "aab";
  std::cout << "The ans of [" << Reference << "] and [" << compare
            << "]= " << RM.isMatch(Reference, compare) << std::endl;
  compare = "mis*is*ip*.";
  Reference = "mississippi";
  std::cout << "The ans of [" << Reference << "] and [" << compare
            << "]= " << RM.isMatch(Reference, compare) << std::endl;
  compare = "a";
  Reference = "aa";
  std::cout << "The ans of [" << Reference << "] and [" << compare
            << "]= " << RM.isMatch(Reference, compare) << std::endl;
  compare = "ab*";
  Reference = "a";
  std::cout << "The ans of [" << Reference << "] and [" << compare
            << "]= " << RM.isMatch(Reference, compare) << std::endl;

  compare = "ab*a";
  Reference = "a";
  std::cout << "The ans of [" << Reference << "] and [" << compare
            << "]= " << RM.isMatch(Reference, compare) << std::endl;

  compare = "a*a";
  Reference = "aaa";
  std::cout << "The ans of [" << Reference << "] and [" << compare
            << "]= " << RM.isMatch(Reference, compare) << std::endl;
            
  return 0;
}