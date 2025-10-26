// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val == 0) { return false; }
        if (root->val == 1) { return true; }
        if (root->val == 2) { return evaluateTree(root->left) || evaluateTree(root->right); };
        if (root->val == 3) { return evaluateTree(root->left) && evaluateTree(root->right); };

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}