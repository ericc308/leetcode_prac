#include "../hpp/someclass.hpp"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MedianHeapTree::sort_to_median_tree() {
  if (data.size() < 2) {
    std::cout << "This tree is null! Please add data.. \n";
  } else {
    for (int idata = data.size() - 1; idata > 2; idata--) {
      if (idata == 1) {
        std::cout << "Final fix..\n";
        view();
        fix_node_down(1);
        std::cout << "After fix..\n";
        view();
      } else {
        // if(is_valid_half_position(idata)<0){
        //   std::cout<<"Exchange..\n";
        //   exchange_to_root(idata);
        //   view();
        //   fix_root();
        //   std::cout<<"After fix..\n";
        //   view();
        // }else{
        //   std::cout<<"fix node:\n";
        //   fix_node(idata);
        //   view();
        // }
        std::cout << "fix node:" << idata << ".\n";
        fix_node_down(idata);
        view();
      }
    }
  }
}
int MedianHeapTree::is_valid_half_position(int index) {
  if (is_right_half_tree(index) > 0) {
    if (data[index] > data[1]) {
      return 1;
    } else {
      return -1;
    }
  } else {
    if (data[index] < data[1]) {
      return 1;
    } else {
      return -1;
    }
  }
}

int MedianHeapTree::is_right_half_tree(int index) {
  int level = return_n_sqrt_of_2(index);
  int num_of_current_level = pow(2, level);
  int index_of_beg_of_current_level = num_of_current_level;
  if (index >= index_of_beg_of_current_level + num_of_current_level / 2) {
    // right half of tree
    return 1;
  } else {
    // left half of tree
    return -1;
  }
}

void MedianHeapTree::exchange_to_root(int index) {
  int val_root = data[1];
  int val_exchange = data[index];
  data[1] = val_exchange;
  data[index] = val_root;
}
void MedianHeapTree::exchange_right_child(int index) {
  std::cout << "Exchange value: " << data[index] << " and " << data[index * 2 + 1] << std::endl;
  int val_root = data[index];
  int val_exchange = data[index * 2 + 1];
  data[index] = val_exchange;
  data[index * 2 + 1] = val_root;
}
void MedianHeapTree::exchange_left_child(int index) {
  std::cout << "Exchange value: " << data[index] << " and " << data[index * 2] << std::endl;
  int val_root = data[index];
  int val_exchange = data[index * 2];
  data[index] = val_exchange;
  data[index * 2] = val_root;
}
void MedianHeapTree::fix_root() {
  // 2020/04/05
  // only consider completed tree condition;
  int length = data.size();
  int index = 1;
  do {
    if (index * 2 > length || index * 2 + 1 > length) {
      // std::cout<<"root : "<<data[index]<<std::endl;
      index = data.size();
    } else {
      // std::cout<<"start to compare root : "<<data[index]<<std::endl;
      // compare right first
      // std::cout<<"Rigth child :"<<data[index*2+1]<<std::endl;
      if (data[index] > data[index * 2 + 1]) {
        exchange_right_child(index);
        index = index * 2 + 1;
      } else {
        // compare left
        // std::cout<<"Left child :"<<data[index*2]<<std::endl;
        if (data[index] < data[index * 2]) {
          exchange_left_child(index);
          index = index * 2;
        } else {
          // it is done.
          index = data.size();
        }
      }
      // compare left first
      // if(data[index] < data[index*2]){
      //   exchange_left_child(index);
      //   index = index*2;
      // }else{
      //   // compare right
      //   // std::cout<<"Left child :"<<data[index*2]<<std::endl;
      //   if(data[index] > data[index*2+1]){
      //     exchange_right_child(index);
      //     index = index*2+1;
      //   }
      //   else{
      //     // it is done.
      //     index = data.size();
      //   }
      // }
    }
  } while (index < data.size());
}

void MedianHeapTree::fix_node(int index) {

  do {
    if (index / 2 < 1) {
      // root node
      index = 0;
    } else {
      // left child
      if (index % 2 == 0) {
        if (data[index] < data[index / 2]) {
          // done
          // fix_node_down(index);
          index = 0;
        } else {
          exchange_left_child(index / 2);
          index = index / 2;
        }

      } else {
        // right child
        if (data[index] > data[index / 2]) {
          // done
          // fix_node_down(index);
          index = 0;
        } else {
          exchange_right_child(index / 2);
          index = index / 2;
        }
      }
    }
  } while (index > 0);
}

void MedianHeapTree::fix_node_down(int index_in) {
  int length = data.size();
  int index = index_in;
  do {
    if (index * 2 > length || index * 2 + 1 > length) {
      // std::cout<<"root : "<<data[index]<<std::endl;
      index = data.size();
    } else {
      // std::cout<<"start to compare root : "<<data[index]<<std::endl;
      // compare right first
      // std::cout<<"Rigth child :"<<data[index*2+1]<<std::endl;
      if (data[index] > data[index * 2 + 1]) {
        exchange_right_child(index);
        index = index * 2 + 1;
      } else {
        // compare left
        // std::cout<<"Left child :"<<data[index*2]<<std::endl;
        if (data[index] < data[index * 2]) {
          exchange_left_child(index);
          index = index * 2;
        } else {
          // it is done.
          index = data.size();
        }
      }
    }
  } while (index < data.size());
}

int MedianHeapTree::get_median() {
  int length = data.size();
  if (length < 2) {
    std::cout << "This tree is null! Please add data.. \n";
    return -1;
  } else {
    return data[1];
  }
}
int MedianHeapTree::get_val(int index) {
  int length = data.size();
  if (index >= length) {
    std::cout << "This tree only has " << length - 1 << " nodes. \n";
    std::cout << "It is too small to find the " << index << "-th data.. \n";
    return -1;
  } else {
    return data[index];
  }
}
int MedianHeapTree::return_n_sqrt_of_2(int num) {
  int n = 0;
  int mod = num / 2;
  while (mod > 0) {
    n++;
    mod = mod / 2;
  }
  return n;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MergeSort::merge_sort(std::vector<int> &array, int ibeg, int iend) {

  if (ibeg < iend) {
    int imid = (ibeg + iend) / 2;
    merge_sort(array, ibeg, imid);
    merge_sort(array, imid + 1, iend);
    merge_sub(array, ibeg, imid, iend);
  }
}
void MergeSort::merge_sub(std::vector<int> &array, int ibeg, int imid, int iend) {
  std::vector<int> left_sub;
  left_sub.assign(array.begin() + ibeg, array.begin() + imid + 1);
  std::vector<int> right_sub;
  right_sub.assign(array.begin() + imid + 1, array.begin() + iend + 1);
  for (int index_sorted = ibeg; index_sorted <= iend; index_sorted++) {
    if (!left_sub.empty()) {
      if (!right_sub.empty()) {
        if (left_sub[0] < right_sub[0]) {
          array[index_sorted] = left_sub[0];
          left_sub.erase(left_sub.begin());
        } else {
          array[index_sorted] = right_sub[0];
          right_sub.erase(right_sub.begin());
        }
      } else {
        array[index_sorted] = left_sub[0];
        left_sub.erase(left_sub.begin());
      }
    } else {
      array[index_sorted] = right_sub[0];
      right_sub.erase(right_sub.begin());
    }
  }
}