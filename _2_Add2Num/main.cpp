#include "hpp/add_2num.hpp"
#include <chrono>
#include <ctime>

// (2 -> 4 -> 3) + (5 -> 6 -> 4)

int main() {
  // \033[shape of fonts;color of fonts;back ground of fonts
  //  shape
  // \033[0m reset all properties
  // \033[1m bright
  // \033[2m half of light
  // \033[3m slope
  // \033[4m under line
  // \033[5m shining
  // \033[6m flicker
  // \033[7m ??
  // \033[8m vanish
  // \033[9m middle line
  // color of fonts
  // 30:black
  // 31:red
  // 32:green
  // 33:yellow
  // 34:blue
  // 35:purple
  // 36:dark
  // 37:white
  // background
  // 40 black
  // 41 red
  // 42 green
  // 43 brown
  // 44 blue
  // 45 wine red
  // 46 noble blue
  // 47 white
  std::cout << " \033[1;31;42mTopic :\033[0m \n";
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

  ListNode L1_1(2);
  ListNode L1_2(4);
  ListNode L1_3(3);
  L1_1.next = &L1_2;
  L1_2.next = &L1_3;
  ListNode L2_1(5);
  ListNode L2_2(6);
  ListNode L2_3(4);
  L2_1.next = &L2_2;
  L2_2.next = &L2_3;

  Solution S;
  ListNode *result = S.addTwoNumbers(&L1_1, &L2_1);

  while (result) {
    std::cout << result->val;
    result = result->next;
  }
  std::cout << std::endl;
  return 0;
}