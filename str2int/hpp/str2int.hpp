#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
class Str2Int{
  public:
  std::vector<int64_t> get_number(std::string input);
  int64_t str_to_int(std::string input){
    char minus = '-';
    int64_t answer=0;
    char front = input[0];
    int length = input.size();
    if(front == minus){
      for(int ich=1;ich<length;ich++){
        std::string sub;
        sub.assign(input.begin()+ich,input.begin()+ich+1);
        answer =  answer + atoi(sub.c_str())*pow(10,(length-ich-1));
      }
      answer = 0 - answer;
    }else{
      for(int ich=0;ich<length;ich++){
        std::string sub;
        sub.assign(input.begin()+ich,input.begin()+ich+1);
        answer =  answer + atoi(sub.c_str())*pow(10,(length-ich-1));
      }
    }
      return answer;
  }

  int isNumber(char in){
    int isnum=-1;
    if(in>=48 && in<=57){
      isnum=1;
    }
    else{
      isnum=-1;
    }
    return isnum;
  }

    int isMinus(char in){
    int isminus=-1;
    if(in==45){
      isminus=1;
    }
    return isminus;
  }

};