#include "hpp/median_two.hpp"


int main(){
    std::cout<<" Median of two sorted array :\n";

    std::vector<int> input{3,5,1,2,11,9,7};
    NodeTree NT;
    NT.add_data(input);
    std::cout<<"Build tree..\n";
    NT.view();
    NT.sort_to_median_tree();

}