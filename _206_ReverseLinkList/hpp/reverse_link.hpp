#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reverse = nullptr;    // new list
        ListNode *temp_next = nullptr;  // temp_node for next
        while(head!=nullptr){
            temp_next = head->next;     // store next
            head->next = reverse;       // connect to last reverse node: let next be last reverse node
            reverse = head;             // update reverse list: let reverse node up
            head = temp_next;           // update head list: let head move to next
        }
        return reverse;
    }
};