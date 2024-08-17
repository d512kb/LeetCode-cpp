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
    int maxLevelSum(TreeNode* root) {
        int maxSum = root->val;
        int level = 0;
        int minLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            ++level;

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                sum += node->val;
            }

            if (sum > maxSum) {
                maxSum = sum;
                minLevel = level;
            }
        }

        return minLevel;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}