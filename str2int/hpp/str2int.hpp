#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
class Str2Int
{
public:
  std::vector<int64_t> get_number(std::string input);
  int get_number_or_warning(std::string input);
  int64_t str_to_int(std::string input) {
    char minus = '-';
    int64_t answer = 0;
    char front = input[0];
    int length = input.size();
    if (front == minus) {
      for (int ich = 1; ich < length; ich++) {
        std::string sub;
        sub.assign(input.begin() + ich, input.begin() + ich + 1);
        answer = answer + atoi(sub.c_str()) * pow(10, (length - ich - 1));
      }
      answer = 0 - answer;
    } else {
      for (int ich = 0; ich < length; ich++) {
        std::string sub;
        sub.assign(input.begin() + ich, input.begin() + ich + 1);
        answer = answer + atoi(sub.c_str()) * pow(10, (length - ich - 1));
      }
    }
    return answer;
  }

  int isNumber(char in) {
    int isnum = -1;
    if (in >= 48 && in <= 57) {
      isnum = 1;
    } else {
      isnum = -1;
    }
    return isnum;
  }

  int isMinus(char in) {
    int isminus = -1;
    if (in == 45) {
      isminus = 1;
    }
    return isminus;
  }
  int islargermax(std::string input) {
    int re = 0;
    int length = input.size();
    std::string max = "2147483648";

    if (length < 10) {
      std::string extension;
      for (int i = 0; i < 10 - length; i++) {
        extension.push_back('0');
      }
      extension.insert(extension.end(), input.begin(), input.end());
      // std::cout << input << std::endl;
      re = extension.compare(max);
    } else if (length > 10) {
      // std::cout << input << std::endl;
      re = 1;
    } else {
      // std::cout << input << std::endl;
      re = input.compare(max);
    }
    return re;
  }

  std::string remove_front_zero(std::string input) {
    int length = input.size();
    if (input.at(0) == '0') {
      for (int inum = 0; inum < length; inum++) {
        if (input.at(inum) == '0') {
          input.assign(input.begin() + 1, input.end());
          inum--;
          length--;
        } else {
          // std::cout << inum << std::endl;
          inum = length;
        }
      }
    }
    return input;
  }
  
};