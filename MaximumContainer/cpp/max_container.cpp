#include "../hpp/max_container.hpp"

int MaxContainer::maxArea(std::vector<int> &height) {
  // brute force O(n2)
  int max_area = 0;
  int length = height.size();
  for (int ibeg = 0; ibeg < length; ibeg++) {
    for (int iend = ibeg + 1; iend < length; iend++) {
      int width = iend - ibeg;
      int temp_max_area = get_area(height[ibeg], height[iend], width);
      if (temp_max_area > max_area) {
        max_area = temp_max_area;
        // std::cout << " max area now : (" << height[ibeg] << "," << height[iend]
        //           << ") =" << max_area << std::endl;
      }
    }
  }
  return max_area;
}

int MaxContainer::maxArea2(std::vector<int> &height) {
  // scan single time O(n)
  // scan from biggest range to smallest range
  int max_area = 0;
  int length = height.size();
  int ibeg = 0, iend = length-1;
  while(ibeg < iend){
    int width = iend - ibeg;
    int temp_max_area = get_area(height[ibeg], height[iend], width);
    if(max_area < temp_max_area){
      max_area = temp_max_area;
    }

    if(height[ibeg] < height[iend]){
      ibeg++;
    }else{
      iend--;
    }
  }

  return max_area;
}

int MaxContainer::get_area(int beg_h, int end_h, int width) {
  int area = 0;
  if (width != 0) {
    if (beg_h < end_h) {
      area = beg_h * width;
    } else {
      area = end_h * width;
    }
  }
  return area;
}
