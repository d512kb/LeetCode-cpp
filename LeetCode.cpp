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
    int getMinimumDifference(TreeNode* root) {
        int result = numeric_limits<int>::max();
        int prevVal = numeric_limits<int>::max();
        helper(root, prevVal, result);
        return result;
    }
private:
    void helper(TreeNode* node, int& prevVal, int& minVal) {
        if (!node)
            return;

        helper(node->left, prevVal, minVal);

        minVal = min(minVal, abs(node->val - prevVal));
        prevVal = node->val;

        helper(node->right, prevVal, minVal);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
