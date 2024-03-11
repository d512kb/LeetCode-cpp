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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricRecur(root->left, root->right);
    }
private:
    bool isSymmetricRecur(TreeNode* nodeLeft, TreeNode* nodeRight) {
        if (!nodeLeft || !nodeRight)
            return nodeLeft == nodeRight;

        return nodeLeft->val == nodeRight->val
            && isSymmetricRecur(nodeLeft->left, nodeRight->right)
            && isSymmetricRecur(nodeLeft->right, nodeRight->left);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
