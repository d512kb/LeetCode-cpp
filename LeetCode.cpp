// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;


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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;

        calcBranchLen(root, result);

        return result;
    }
private:
    int calcBranchLen(TreeNode* root, int& diameter) {
        if (!root) {
            return -1;
        }

        int leftBranchLen = 1 + calcBranchLen(root->left, diameter);
        int rightBranchLen = 1 + calcBranchLen(root->right, diameter);

        diameter = max(diameter, leftBranchLen + rightBranchLen);

        return max(leftBranchLen, rightBranchLen);
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}