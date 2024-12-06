// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) { return root; }

        if (root->val > p->val && root->val > q->val) { return lowestCommonAncestor(root->left, p, q); }
        if (root->val < p->val && root->val < q->val) { return lowestCommonAncestor(root->right, p, q); }

        return root;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}