#include "test_assistant.hpp"
TEST(MergeSort, merge_sort_algorithm) {
  TestAssistant TA;
  std::vector<int> array{3, 1, 2, 5, 7, 4, 10, 11};
  std::vector<int> ans{1, 2, 3, 4, 5, 7, 10, 11};
  // std::cout<<"Before sorting:\n";
  // TA.view_vector_array(array);
  MergeSort MS;
  MS.merge_sort(array, 0, array.size() - 1);
  // std::cout<<"After sorting:\n";
  // TA.view_vector_array(array);
  for (int idata = 0; idata < array.size(); idata++) {
    EXPECT_EQ(ans[idata], array[idata]);
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}