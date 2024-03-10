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
    ListNode* partition(ListNode* head, int x) {
        ListNode* preHead = new ListNode(0, head);
        ListNode* insertAfter = preHead;
        ListNode* node = preHead;

        while (node->next) {
            if (node->next->val < x) {
                auto nodeToMove = node->next;

                if (nodeToMove != insertAfter->next) {
                    node->next = nodeToMove->next;
                    nodeToMove->next = insertAfter->next;
                    insertAfter->next = nodeToMove;
                } else {
                    node = node->next;
                }

                insertAfter = nodeToMove;
            } else {
                node = node->next;
            }
        }

        head = preHead->next;
        delete preHead;

        return head;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
