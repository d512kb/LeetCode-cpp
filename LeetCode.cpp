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
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* r = new ListNode(0);
         ListNode* n = r;
         int c = 0;

         while (l1 && l2) {
             n->next = new ListNode(l1->val + l2->val + c);
             n = n->next;
             c = n->val / 10;
             n->val %= 10;

             l1 = l1->next;
             l2 = l2->next;
         }

         auto l = l1 ? l1 : l2;

         while (l) {
             n->next = new ListNode(l->val + c);
             n = n->next;
             c = n->val / 10;
             n->val %= 10;

             l = l->next;
         }

         if (c) {
             n->next = new ListNode(1);
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
