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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* preHead = new ListNode(0, head);
        ListNode* prev = preHead;

        while (head && head->next) {
            if (head->val == head->next->val) {
                int val = head->val;

                while (head && head->val == val) {
                    auto next = head->next;
                    delete head;
                    head = next;
                }

                prev->next = head;
                continue;
            }

            prev = head;
            head = head->next;
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
