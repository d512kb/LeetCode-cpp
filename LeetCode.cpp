// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int s = 0;

        if (root->left) {
            if (root->left->left == nullptr && root->left->right == nullptr) { s += root->left->val; }

            s += sumOfLeftLeaves(root->left);
        }
        if (root->right) {
            s += sumOfLeftLeaves(root->right);
        }

        return s;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}