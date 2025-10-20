// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) { return nullptr; }
        if (original == target) { return cloned; }

        auto left = getTargetCopy(original->left, cloned->left, target);
        if (left) { return left; }

        return getTargetCopy(original->right, cloned->right, target);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}