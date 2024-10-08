// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a binary tree node.
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) { return false; }

        return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isIdentical(TreeNode* tree1, TreeNode* tree2) {
        if (!tree1) { return !tree2; }
        if (!tree2) { return false; }

        return tree1->val == tree2->val && isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}