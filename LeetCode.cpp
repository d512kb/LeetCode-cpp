// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution {
 public:
     bool hasCycle(ListNode* head) {
         ListNode* node = head;

         while (head && node && node->next) {
             head = head->next;
             node = node->next->next;

             if (head == node)
                 return true;
         }

         return false;
     }
 };

int main() {
    INIT_TIME(timer);
        
    PRINT_ELAPSED(timer);
    return 0;
}
