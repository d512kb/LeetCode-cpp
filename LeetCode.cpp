// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode preHead;
        preHead.next = head;

        ListNode* prev = &preHead;

        while (head) {
            if (head->val == val) {
                prev->next = head->next;
                delete head;
                head = prev->next;
            }
            else {
                prev = head;
                head = head->next;
            }
        }

        return preHead.next;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}