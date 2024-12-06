// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        while (slow != nullptr) {
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        auto left = head;
        auto right = prev;
        auto last = left;

        while (left != right) {
            if (last == left) {
                left = left->next;
                last->next = right;
                last = right;
            } else {
                right = right->next;
                last->next = left;
                last = left;
            }
        }
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}