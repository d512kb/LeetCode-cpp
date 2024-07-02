// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy;
        ListNode* prevFirst = &dummy;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* result = second;

        while (first && second) {
            ListNode* secondNext = second->next;

            second->next = first;
            prevFirst->next = second;
            prevFirst = first;

            first = secondNext;
            second = secondNext ? secondNext->next : nullptr;
        }

        prevFirst->next = first;

        return result;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}