// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <limits>

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
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        stack<TreeNode*> backtrace;
        uint64_t result{ 0 };

        while (root != nullptr) {
            if (root->val >= low && root->val <= high)
                result += root->val;

            if (root->right != nullptr && root->val < high)
                backtrace.push(root->right);

            if (root->left != nullptr && root->val > low)
                root = root->left;
            else {
                if (backtrace.empty()) {
                    root = nullptr;
                } else {
                    root = backtrace.top();
                    backtrace.pop();
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    PRINT_ELAPSED(timer);

    return 0;
}
