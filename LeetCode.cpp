// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return getBranchLen(root, 1).first;
    }
private:
    pair<TreeNode*, int> getBranchLen(TreeNode* node, int len) {
        if (!node) { return { nullptr, len }; }

        auto left = getBranchLen(node->left, len + 1);
        auto right = getBranchLen(node->right, len + 1);

        if (left.second == right.second) { return { node, left.second }; }
        if (left.second > right.second) { return left; }
        return right;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}