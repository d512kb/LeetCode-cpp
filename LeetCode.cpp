// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto heightX = calcHeight(root, nullptr, x, 0);
        auto heightY = calcHeight(root, nullptr, y, 0);

        return heightX.first != heightY.first && heightX.second == heightY.second;
    }
private:
    pair<TreeNode*, int> calcHeight(TreeNode* node, TreeNode* parent, int v, int h) {
        if (!node) { return {}; }
        if (node->val == v) { return { parent, h }; }

        auto heightLeft = calcHeight(node->left, node, v, h + 1);
        if (heightLeft.first) { return heightLeft; }

        return calcHeight(node->right, node, v, h + 1);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}