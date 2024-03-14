// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;

        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        TreeNode* b = lowestCommonAncestor(root->right, p, q);

        if (a && b)
            return root;

        return !a ? b : !b ? a : nullptr;
    }
};

int main() {
    INIT_TIME(timer);

    TreeNode tn[]{ 0,1,2,3,4,5,6,7,8,9 };
    tn[3].left = &tn[5];
    tn[3].right = &tn[1];
    tn[5].left = &tn[6];
    tn[5].right = &tn[2];
    tn[2].left = &tn[7];
    tn[2].right = &tn[4];

    Solution sol;
    auto p = sol.lowestCommonAncestor(&tn[3], &tn[6], &tn[4]);

    PRINT_ELAPSED(timer);
    return 0;
}
