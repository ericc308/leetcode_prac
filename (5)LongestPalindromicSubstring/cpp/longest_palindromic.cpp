#include "../hpp/longest_palindromic.hpp"

std::string LongestPalindromic::get_longest_palindromic_sub_string(std::string input){
  std::string max_palin_str;
  int max_palin_length = input.size();
  int first_palin=0;
  for(int istr=max_palin_length;istr>0;istr--){
    std::string sub_string;
    for(int ioffset=0;ioffset<max_palin_length-istr+1;ioffset++){
      sub_string.assign(input.begin()+ioffset,input.begin()+ioffset+istr);
      // std::cout<<"mid capture substring :"<<sub_string<<std::endl;
      if(is_palindromic(sub_string)){
        ioffset=max_palin_length-istr;
        first_palin = 1;
        // std::cout<<"Is palin!\n";
      }
    }
    if(first_palin){
      istr=0;
      max_palin_str.assign(sub_string.begin(),sub_string.end());
    }
  }
  return  max_palin_str;
}
int LongestPalindromic::is_palindromic(std::string input){
  int length = input.size();
  int mid = length/2;
  int is_palin = 1;
  for(int ichar=0; ichar<mid ; ichar++){
    if(input.at(ichar)!=input.at(length-ichar-1)){
      is_palin = 0;
      ichar = mid;
    }
  }
  return is_palin;
}