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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderHelper(root, 1, result);
        return result;
    }
private:
    void levelOrderHelper(TreeNode* node, int h, vector<vector<int>>& nodes) {
        if (!node)
            return;

        if (h > nodes.size())
            nodes.emplace_back();

        nodes[h - 1].push_back(node->val);

        levelOrderHelper(node->left, h + 1, nodes);
        levelOrderHelper(node->right, h + 1, nodes);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
