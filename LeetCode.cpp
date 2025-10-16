// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;

        while (node && node->next) {
            if (node->val == node->next->val) {
                ListNode* n = node->next;
                node->next = node->next->next;
                delete n;
            }
            else {
                node = node->next;
            }
        }

        return head;
    }
};

int main()
{
    INIT_TIME(timer);
 
    PRINT_ELAPSED(timer);
    return 0;
}