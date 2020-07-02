#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

class Solution {
  public:
  std::string intToRoman(int num) {
    std::string result;
    std::string check_str[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int check_num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    int iend = 13-1;
      for(int inum = iend;inum>-1;inum--){
        int quo = num / check_num[inum];
        num = num % check_num[inum];
        if(quo > 0){
          for(int item=0;item<quo;item++){
            result = result + (check_str[inum]);
          }
        }
      }
    return result;
  }
};