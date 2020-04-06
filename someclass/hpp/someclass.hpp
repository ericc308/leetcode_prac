#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class MedianHeapTree
{ // cannot be used now

  std::vector<int> data;

public:
  MedianHeapTree() { data.push_back(0); }
  ~MedianHeapTree() {}
  void add_data(std::vector<int> input_list) { data.insert(data.end(), input_list.begin(), input_list.end()); }
  void sort_to_median_tree();
  int get_median();
  int get_val(int index);
  int is_valid_half_position(int index);
  void exchange_to_root(int index);
  void exchange_right_child(int index);
  void exchange_left_child(int index);
  void fix_root();
  void fix_node(int index);
  void fix_node_down(int index);
  int return_n_sqrt_of_2(int num);
  int is_right_half_tree(int index);
  std::vector<int> get_tree() { return data; }
  void view() {
    int index = 1;
    for (int expnum = 1; index < data.size(); expnum++) {
      std::cout << "Level " << expnum << ": ";
      int beg = index;
      for (int idata = beg; index < pow(2, expnum) && index < data.size(); idata++) {
        std::cout << data[idata] << " ";
        index++;
      }
      std::cout << std::endl;
    }
  }
};

class MergeSort
{
public:
  void merge_sort(std::vector<int> &array, int ibeg, int iend);
  void merge_sub(std::vector<int> &array, int ibeg, int imid, int iend);
};