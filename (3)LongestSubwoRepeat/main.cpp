#include "hpp/find_sub.hpp"


int main(){
std::cout<<" find_sub :\n";
std::string input = "abcabcbb";
Solution FS;
int ans = FS.lengthOfLongestSubstring(input);

std::cout<<"The '"<< input <<"' longest wo repeated string is "<<ans<<std::endl;
input = "aab";
ans = FS.lengthOfLongestSubstring(input);
std::cout<<"The '"<< input <<"' longest wo repeated string is "<<ans<<std::endl;
input = "aabaab!bb";
ans = FS.lengthOfLongestSubstring(input);
std::cout<<"The '"<< input <<"' longest wo repeated string is "<<ans<<std::endl;
}