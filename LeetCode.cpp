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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* lastOdd = head;
        ListNode* headEven = head->next;
        ListNode* lastEven = headEven;
        ListNode* node = head->next->next;

        while (node) {
            lastOdd->next = node;
            lastOdd = node;
            lastEven->next = node->next;
            lastEven = node->next;

            if (lastEven) {
                node = lastEven->next;
            } else {
                node = nullptr;
            }
        }

        lastOdd->next = headEven;
        return head;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}