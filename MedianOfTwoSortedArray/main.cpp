#include "hpp/median_two.hpp"

int main() {
  std::cout << " Median of two sorted array :\n";

  std::vector<int> input{1, 2};
  std::vector<int> input2{4, 5};
  std::vector<int> input3{1, 2, 3, 4};
  std::vector<int> input4{7};
  std::vector<int> input5{6, 7, 9, 10};
  std::vector<int> input6{3};
  std::vector<int> input7{4};
  std::vector<int> input8{5, 6, 7};
  std::vector<int> input9{8};
  MedianTwo MT;
  MT.findMedianSortedArrays(input, input2);
  std::cout << "Med of [1,2] [4,5] : "
            << MT.findMedianSortedArrays(input, input2) << std::endl;
  std::cout << "Med of [1, 2, 3, 4][7] : "
            << MT.findMedianSortedArrays(input3, input4) << std::endl;
  std::cout << "Med of [6,7,9,10] [3] : "
            << MT.findMedianSortedArrays(input5, input6) << std::endl;
  std::cout << "Med of  [4] [5 6 7] : "
            << MT.findMedianSortedArrays(input7, input8) << std::endl;
  std::cout << "Med of [8] [5 6 7] : "
            << MT.findMedianSortedArrays(input9, input8) << std::endl;
}