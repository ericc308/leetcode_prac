#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

const std::map<std::string, int> check_str = {
  {"I", 1},
  {"IV", 4},
  {"V", 5},
  {"IX", 9},
  {"X", 10},
  {"XL", 40},
  {"L", 50},
  {"XC", 90},
  {"C", 100},
  {"CD", 400},
  {"D", 500},
  {"CM", 900},
  {"M", 1000}
};

class Solution {
  public:
  int romanToInt(std::string input) {
    int length = input.length();
    int total = 0;
    for(int ichar = 0; ichar < length; ichar++){
      std::string sub_str;
      if(ichar+1<length){
        sub_str.push_back(input.at(ichar));
        sub_str.push_back(input.at(ichar+1));
        if(auto iter = check_str.find(sub_str); iter != check_str.end()){
          std::cout<<sub_str<<std::endl;
          total = total + iter->second;
          ichar++;
        }else{  // only need one character
          sub_str.erase(1);
          if(auto iter = check_str.find(sub_str); iter != check_str.end()){
            std::cout<<sub_str<<std::endl;
            total = total + iter->second;
          }else{  // not roman character
            std::cout<<"error : cannot find this usage '"<< sub_str <<"' in roman.\n";
          }
        }
      }else{  // the end character
        sub_str.push_back(input.at(ichar));
        if(auto iter = check_str.find(sub_str); iter != check_str.end()){
          std::cout<<sub_str<<std::endl;
          total = total + iter->second;
        }else{  // not roman character
          std::cout<<"error : cannot find this usage '"<< sub_str <<"' in roman.\n";
        }
      }
    }
    return total;
  }
};