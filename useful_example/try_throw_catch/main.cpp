#include <iostream>
/*
  Create function in try{}, throw something when error occur.
  catch that type of something, then handle it.
*/
struct BadValue : public std::exception {};

int someprocess(int a, int b){
  if(a-b < 0){
    int *ans = new int[2];
    ans[0] = a;
    ans[1] = b;
    throw ans;
  }
  return a-b;
}

int main(void) {
    try {
      int error = 0;
      error = someprocess(2,1);
      error = someprocess(3,1);
      error = someprocess(5,1);
      error = someprocess(2,4);
      error = someprocess(3,1);
      error = someprocess(5,1);

    }
    catch (int *e) {
        std::cout << "some thing wrong with caculation:" << std::endl;
        std::cout << "a: "<<e[0]<<std::endl;
        std::cout << "b: "<<e[1]<<std::endl;
    }
 
    return 0;
}
