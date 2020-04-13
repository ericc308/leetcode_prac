#include "../hpp/zig_zag.hpp"

std::string ZigZag::convert(std::string input, int numRows) {
  std::string ans;
  int max_length = input.size();
  // first row
  if(numRows > 1){
    for (int idata = 0; idata < max_length;
        idata = idata + numRows + numRows - 2) {
      ans.push_back(input.at(idata));
    }
  }else{
    for (int idata = 0; idata < max_length; idata++) {
      ans.push_back(input.at(idata));
    }
  }
  // mid row
  if (numRows > 2) {
    for (int imid = 1; imid < numRows - 1; imid++) {
      for (int idata = imid; idata < max_length; idata = idata + numRows + numRows - 2) {
        int n_th_z_row = idata / (numRows + numRows - 2);
        int i_th_data_per_repeat = idata % (numRows + numRows - 2);
        ans.push_back(input.at(idata));
        if ((idata + numRows + numRows - 2 - (2 * imid)) < max_length){
          ans.push_back(input.at(idata + numRows + numRows - 2 - (2 * imid)));
        }
      }
    }
  }
  // Last row
  if (numRows > 1) {
    for (int idata = numRows - 1; idata < max_length;
         idata = idata + numRows + numRows - 2) {
      ans.push_back(input.at(idata));
    }
  }
  std::cout << " Data after: \n";
  for (int ida = 0; ida < ans.size(); ida++) {
    std::cout << ans[ida];
  }
  std::cout << std::endl;
  return ans;
}