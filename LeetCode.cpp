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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;

        maxDepthRecur(root, 0, maxDepth);

        return maxDepth;
    }

private:
    void maxDepthRecur(TreeNode* root, int depth, int& maxDepth) {
        if (!root) {
            maxDepth = max(maxDepth, depth);
            return;
        }

        maxDepthRecur(root->left, depth + 1, maxDepth);
        maxDepthRecur(root->right, depth + 1, maxDepth);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
