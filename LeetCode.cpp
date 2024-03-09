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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        for (int i = 1; i < n; ++i) {
            fast = fast->next;
        }

        ListNode* preHead = new ListNode(0, head);
        ListNode* prev = preHead;

        while (fast->next) {
            prev = head;
            head = head->next;
            fast = fast->next;
        }

        head = head->next;
        delete prev->next;
        prev->next = head;

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
