// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };
 
 class Solution {
 public:
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* r = new ListNode(0);
         ListNode* n = r;

         while (list1 && list2) {
             n->next = new ListNode(0);
             n = n->next;

             if (list1->val <= list2->val) {
                 n->val = list1->val;
                 list1 = list1->next;
             } else {
                 n->val = list2->val;
                 list2 = list2->next;
             }
         }

         auto list = list1 ? list1 : list2;

         while (list) {
             n->next = new ListNode(0);
             n = n->next;
             n->val = list->val;
             list = list->next;
         }

         auto result = r->next;
         delete r;

         return result;
     }
 };

int main() {
    INIT_TIME(timer);
        
    PRINT_ELAPSED(timer);
    return 0;
}
