#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = new ListNode(0);
    ListNode *temp;
    int sum = 0;
    sum = (l1->val + l2->val) % 10;
    result->val = sum;
    int carry = 0;
    carry = (l1->val + l2->val + carry) / 10;
    l1 = l1->next;
    l2 = l2->next;
    temp = result;
    std::cout << "sum :" << sum << " car :" << carry << std::endl;
    while (l1 || l2) {
      if (l1 && l2) {
        sum = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode *newnode = new ListNode(sum);
        temp->next = newnode;
        temp = temp->next;
        std::cout << "sum :" << sum << " car :" << carry << std::endl;
      } else {
        if (l1) { // l1 > l2
          sum = (l1->val + 0 + carry) % 10;
          carry = (l1->val + 0 + carry) / 10;
          l1 = l1->next;
          ListNode *newnode = new ListNode(sum);
          temp->next = newnode;
          temp = temp->next;
          std::cout << "sum :" << sum << " car :" << carry << std::endl;
        } else { // l2 > l1
          sum = (l2->val + 0 + carry) % 10;
          carry = (l2->val + 0 + carry) / 10;
          l2 = l2->next;
          ListNode *newnode = new ListNode(sum);
          temp->next = newnode;
          temp = temp->next;
          std::cout << "sum :" << sum << " car :" << carry << std::endl;
        }
      }
    }
    if (carry) {
      ListNode *newnode = new ListNode(1);
      temp->next = newnode;
      temp = temp->next;
    }
    return result;
  }
  int get_len(ListNode *l1) {
    int len = 0;
    ListNode *now = l1;
    while (now->next != nullptr) {
      len++;
      now = now->next;
    }
    return len;
  }
};