#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class MedianTwo {
public:
  double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {

    vector<int> mergearr;
    while (!nums1.empty() || !nums2.empty()) {
      if (!nums1.empty()) {
        if (!nums2.empty()) {
          if (nums1[0] < nums2[0]) {
            mergearr.push_back(nums1[0]);
            nums1.erase(nums1.begin());
          } else {
            mergearr.push_back(nums2[0]);
            nums2.erase(nums2.begin());
          }
        } else {
          mergearr.push_back(nums1[0]);
          nums1.erase(nums1.begin());
        }
      } else {
        mergearr.push_back(nums2[0]);
        nums2.erase(nums2.begin());
      }
    }

    // for (int i = 0; i < mergearr.size(); i++) {
    //   std::cout << mergearr[i] << " ";
    // }
    // std::cout << std::endl;
    return get_median_of_array(mergearr);
  }

  double get_median_of_array(vector<int> &nums1) {
    int num_array = nums1.size();
    double med = 0;
    if (iseven(num_array)) {
      med =
          static_cast<double>(nums1[num_array / 2] + nums1[num_array / 2 - 1]) /
          2;
    } else {
      med = static_cast<double>(nums1[floor(num_array / 2)]);
    }
    return med;
  }
  int iseven(int num) {
    if (num % 2 == 0) {
      return 1;
    } else {
      return 0;
    }
  }
  void view(std::vector<int> &arr) {
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