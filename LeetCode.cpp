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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        rightSideViewHelper(root, 1, result);

        return result;
    }
private:
    void rightSideViewHelper(TreeNode* node, int h, vector<int>& nodes) {
        if (!node)
            return;

        if (h > nodes.size())
            nodes.push_back(node->val);

        rightSideViewHelper(node->right, h + 1, nodes);
        rightSideViewHelper(node->left, h + 1, nodes);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
