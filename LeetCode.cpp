// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a binary tree node.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<char> toDelete(1000 + 1);

        for (int val : to_delete) {
            toDelete[val] = 1;
        }

        vector<TreeNode*> result;
        if (delNodes(root, toDelete, result)) {
            result.push_back(root);
        }

        return result;
    }
private:
    TreeNode* delNodes(TreeNode* node, vector<char>& toDelete, vector<TreeNode*>& result) {
        if (!node)
            return nullptr;

        node->left = delNodes(node->left, toDelete, result);
        node->right = delNodes(node->right, toDelete, result);

        if (toDelete[node->val]) {
            if (node->left) result.push_back(node->left);
            if (node->right) result.push_back(node->right);

            delete node;
            return nullptr;
        }

        return node;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}