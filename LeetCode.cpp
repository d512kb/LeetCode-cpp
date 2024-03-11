// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* preHead = new ListNode(0, head);
        ListNode* kHead = preHead;
        ListNode* kHeadPrev = nullptr;
        int i = 0;

        while (node) {
            ListNode* kTail = node;

            for (i = 0; node && i < k; ++i) {
                next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }

            kHead->next = prev;
            kHeadPrev = kHead;
            kHead = kTail;
        }

        if (i == k) {
            kHead->next = nullptr;
        } else {
            prev = nullptr;
            node = kHeadPrev->next;

            while (--i >= 0) {
                next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }

            kHeadPrev->next = prev;
        }

        head = preHead->next;
        delete preHead;

        return head;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;

    vector<ListNode> ln{ ListNode(1), ListNode(2), ListNode(3), ListNode(4) };
    ln[0].next = &ln[1];
    ln[1].next = &ln[2];
    ln[2].next = &ln[3];

    auto head = sol.reverseKGroup(&ln[0], 2);

    PRINT_ELAPSED(timer);
    return 0;
}
