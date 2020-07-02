#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
class MaxContainer {
public:
  int maxArea(std::vector<int> &height);
  int maxArea2(std::vector<int> &height);
  int get_area(int beg_h, int end_h, int width);
};