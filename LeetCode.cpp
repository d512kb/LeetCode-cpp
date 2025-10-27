// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;

        while (head) {
            ans = ans * 2 + head->val;
            head = head->next;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}