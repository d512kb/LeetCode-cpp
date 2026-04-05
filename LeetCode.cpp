// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int result = numeric_limits<int>::max();
        int prevVal = numeric_limits<int>::max();

        inOrder(root, prevVal, result);

        return result;
    }
private:
    void inOrder(TreeNode* node, int& prevVal, int& result) {
        if (!node) { return; }

        inOrder(node->left, prevVal, result);

        result = min(result, abs(node->val - prevVal));
        prevVal = node->val;

        inOrder(node->right, prevVal, result);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}