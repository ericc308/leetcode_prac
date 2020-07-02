#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int idata=0;idata<nums.size();idata++){
            if(nums[idata]==val){
                nums.erase(nums.begin()+idata);
                idata--;
            }
        }
        return nums.size();
    }
};
int main(){

Solution s;
vector<int> test_num{0,1,2,2,3,0,4,2};
int cut = 2;
vector<int> ans_num{0,1,3,0,4};
int ans_len = 5;

if(s.removeElement(test_num,cut)==ans_len){
  int diff=0;
  for(int inum=0;inum<test_num.size();inum++){
    if(ans_num[inum]!=test_num[inum]){
      diff=1;
    }
  }
  if(diff==0){
    std::cout << "\033[1;32mPASS!!\033[0m\n";
  }else{
  std::cout << "\033[1;31mFAIL!!\033[0m\n";
}
}else{
  std::cout << "\033[1;31mFAIL!!\033[0m\n";
}


return 0;
};