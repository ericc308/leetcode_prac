#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class TwoSum {
public:
    TwoSum(){};
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int a=0;
        int b=0;
        for(int i =0;i<nums.size();i++){
            a = nums[i];
            for(int j=i+1;j<nums.size();j++){
                b = nums[j];
                if(target==(a+b)){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};