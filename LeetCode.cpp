// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;

        while (node->next) {
            ListNode* gcdNode = new ListNode(gcd(node->val, node->next->val), node->next);
            node->next = gcdNode;
            node = gcdNode->next;
        }

        return head;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}