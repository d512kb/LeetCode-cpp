// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) { return false; }

        return containsPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
private:
    bool containsPath(ListNode* head, TreeNode* node) {
        if (!head) { return true; }
        if (!node) { return false; }
        if (node->val != head->val) { return false; }

        return containsPath(head->next, node->left) || containsPath(head->next, node->right);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}