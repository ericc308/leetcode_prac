#include "hpp/two_sum.hpp"

class TestCenter{
  public:
  int isSame(int expect, int input){
    if(expect==input){
      return 1;
    }
    else{
      return 0;
    }
  }
};

int main(){
  TestCenter TC;
std::cout<<" Two sum :\n";
vector<int> input{2, 7, 11, 15};
int target = 9;
vector<int> ans{0,1};
TwoSum TS;
vector<int>result = TS.twoSum(input,target);
if(TC.isSame(ans[0],result[0])){
  cout<<"PASS!\n";
}
else{
  cout<<"FAIL!\n";
}
return 0;
}