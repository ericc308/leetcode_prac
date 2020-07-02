#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::string com_max;
        std::string temp_max;
        int len_max = 0;
        int len_temp = 0;
        for(int ichar=0;ichar<s.length();ichar++){
            int irepeated = isRepeated(temp_max, s[ichar]);
            if( irepeated == 0){
                temp_max.push_back(s[ichar]);
                if(temp_max.length() >= com_max.length()){
                    com_max.assign(temp_max.begin(),temp_max.end());
                    len_max = temp_max.length();
                }
            }else{
                temp_max.assign(temp_max.begin()+irepeated, temp_max.end());
                temp_max.push_back(s[ichar]);
            }
        }
        return len_max;
        
    }

    int isRepeated(std::string str, char word){
        int isR=0;
        for(int i =0;i<str.length();i++){
            if(str[i]==word){
                isR = i + 1;
                return isR;
            }
        }
        return isR;
    }
};