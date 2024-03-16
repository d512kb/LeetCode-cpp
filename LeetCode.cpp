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
    bool isValidBST(TreeNode* root) {
        int64_t p = numeric_limits<int64_t>::min();
        return helper(root, p);
    }

private:
    bool helper(TreeNode* node, int64_t& prevVal) {
        if (!node)
            return true;

        bool left = helper(node->left, prevVal);

        if (node->val <= prevVal)
            return false;

        prevVal = node->val;

        return left && helper(node->right, prevVal);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
