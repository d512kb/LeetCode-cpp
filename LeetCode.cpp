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
    bool isPalindrome(ListNode* head) {
        ListNode* preHead = new ListNode(0, head);
        ListNode* node = preHead;
        ListNode* fastNode = head;

        // find mid point        
        while (fastNode && fastNode->next) {
            node = node->next;
            fastNode = fastNode->next->next;
        }

        ListNode* secondHalf = node->next;

        // reverse first half
        ListNode* prev = nullptr;
        node = head;
        while (node != secondHalf) {
            ListNode* preNext = node->next;
            node->next = prev;
            prev = node;
            node = preNext;
        }

        node = prev;
        prev = secondHalf;
        bool isPalindrome = true;

        if (fastNode) { // odd number of items
            secondHalf = secondHalf->next;
        }

        while (node) {
            isPalindrome = isPalindrome && node->val == secondHalf->val;
            secondHalf = secondHalf->next;

            ListNode* preNext = node->next;
            node->next = prev;
            prev = node;
            node = preNext;
        }

        delete preHead;
        return isPalindrome;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}