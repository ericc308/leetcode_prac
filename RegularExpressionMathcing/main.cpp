#include "hpp/regular_mathcing.hpp"
#include <chrono>
#include <ctime>
int main() {
  // \033[shape of fonts;color of fonts;back ground of fonts
  RegularMathcing RM;

  std::cout << "\033[1;33;42mRegular Experession Mathcing\033[0m :\n";
  std::string test = "abc";
  auto start = std::chrono::steady_clock::now();
  std::vector<std::string> result = RM.get_sub_pattern(test);

  auto end = std::chrono::steady_clock::now();
  for (int ist = 0; ist < result.size(); ist++) {
    std::cout << result[ist] << std::endl;
  }

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

  std::string test2 = "abcd";
  std::cout << "Ans:" << RM.isSubstringEqual(test, test2, 0, 4) << std::endl;
}