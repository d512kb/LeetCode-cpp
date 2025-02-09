// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        subtreeSize(root, ans);

        return ans;
    }
private:
    pair<int, int> subtreeSize(TreeNode* node, int& equalNodesNumber) {
        if (!node) { return {}; }

        auto leftTree = subtreeSize(node->left, equalNodesNumber);
        auto rightTree = subtreeSize(node->right, equalNodesNumber);

        leftTree.first += node->val + rightTree.first;
        leftTree.second += 1 + rightTree.second;

        if (leftTree.first / leftTree.second == node->val) { ++equalNodesNumber; }

        return leftTree;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}