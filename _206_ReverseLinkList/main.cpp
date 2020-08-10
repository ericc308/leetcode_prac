#include "hpp/reverse_link.hpp"

void addNode(ListNode *list, ListNode *new_node){
  ListNode *temp = list;
  while(temp->next != nullptr){
    temp = temp -> next;
  }
  temp->next = new_node;
}

void view_list(ListNode *list){
  ListNode *temp = list;
  std::cout<<"[";
  while(temp != nullptr){
    std::cout <<" "<< temp->val <<" ";
    temp = temp -> next;
  }
  std::cout<<"]";
}

int main(){

ListNode a(1);
ListNode b(2);
ListNode c(3);
ListNode d(4);
ListNode e(5);
addNode(&a,&b);
addNode(&a,&c);
addNode(&a,&d);
addNode(&a,&e);
view_list(&a);

Solution S1;
ListNode *k = S1.reverseList(&a);

view_list(k);
return 0;
}