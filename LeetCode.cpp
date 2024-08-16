// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast) {
            fast = fast->next->next;
            ListNode* preNext = slow->next;
            slow->next = prev;
            prev = slow;
            slow = preNext;
        }

        int result = 0;
        ListNode* backward = prev;
        prev = slow;

        while (slow) {
            result = max(result, slow->val + backward->val);

            ListNode* preNext = backward->next;
            backward->next = prev;
            prev = backward;
            backward = preNext;
            slow = slow->next;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}