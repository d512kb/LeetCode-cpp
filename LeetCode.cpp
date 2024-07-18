// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        return robHelper(root).first;
    }
private:
    pair<int, int> robHelper(TreeNode* node) {
        if (!node)
            return { 0, 0 };

        auto leftTree = robHelper(node->left);
        auto rightTree = robHelper(node->right);

        int robThis = node->val + leftTree.second + rightTree.second;
        int robThat = leftTree.first + rightTree.first;

        return { max(robThis, robThat), robThat };
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}