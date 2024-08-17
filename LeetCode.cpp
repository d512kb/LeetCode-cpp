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
    unordered_map<int64_t, int> m_sums{ {0,1} };
public:
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
private:
    int dfs(TreeNode* node, int64_t sum, int targetSum) {
        if (!node) {
            return 0;
        }

        sum += node->val;

        ++m_sums[sum];
        int leftSum = dfs(node->left, sum, targetSum);
        int rightSum = dfs(node->right, sum, targetSum);
        --m_sums[sum];

        return m_sums[sum - targetSum] + leftSum + rightSum;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}