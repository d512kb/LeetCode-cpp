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
    int maxPathSum(TreeNode* root) {
        calcTree(root);
        return m_maxSum;
    }

private:
    int calcTree(TreeNode* node) {
        if (!node)
            return 0;

        int leftSum = calcTree(node->left);
        int rightSum = calcTree(node->right);
        int maxSum = leftSum > rightSum ? leftSum : rightSum;
        int sum = node->val + leftSum + rightSum;

        m_maxSum = sum > m_maxSum ? sum : m_maxSum;

        return node->val + maxSum > 0 ? node->val + maxSum : 0;
    }
    int m_maxSum{ numeric_limits<int>::min() };
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
