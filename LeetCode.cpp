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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* node = head;
        int c = 1;

        while (c < left) {
            prev = node;
            node = node->next;
            ++c;
        }

        ListNode* preLeft = prev;
        ListNode* leftNode = node;

        while (c <= right) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
            ++c;
        }

        if (left > 1)
            preLeft->next = prev;

        leftNode->next = node;

        return left > 1 ? head : prev;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
