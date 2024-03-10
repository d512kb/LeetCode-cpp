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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;

        ListNode* node = head;
        int n = 1;

        while (node->next) {
            node = node->next;
            ++n;
        }

        int s = n - k % n;
        node->next = head;

        for (; s > 0; --s) {
            node = node->next;
        }

        head = node->next;
        node->next = nullptr;

        return head;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
