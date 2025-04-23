// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);

        ListNode* node = head;
        char c = 0;

        while (node) {
            int val = 2 * node->val + c;
            node->val = val % 10;
            c = val / 10;
            node = node->next;
        }

        head = reverseList(head);

        if (c) {
            ListNode* newHead = new ListNode(1, head);
            head = newHead;
        }

        return head;
    }

private:
    ListNode* reverseList(ListNode* head) const {
        ListNode* preHead = nullptr;

        while (head) {
            ListNode* next = head->next;
            head->next = preHead;
            preHead = head;
            head = next;
        }

        return preHead;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}