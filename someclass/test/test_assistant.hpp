#ifndef TEST_ASSISTANT_H
#define TEST_ASSISTANT_H

#include "../hpp/someclass.hpp"
#include <gtest/gtest.h>
class TestAssistant
{
public:
  void view_vector_array(std::vector<int> &arr) {
    if (!arr.empty()) {
      std::cout << "[ ";
      for (int idata = 0; idata < arr.size(); idata++) {
        std::cout << arr[idata] << " ";
      }
      std::cout << "]\n";
    } else {
      std::cout << "[ ]\n";
    }
  }
};

#endif