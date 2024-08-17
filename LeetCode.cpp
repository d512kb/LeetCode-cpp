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
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeHelper(root, key);
    }
private:
    TreeNode* deleteNodeHelper(TreeNode* node, int key) {
        if (!node) {
            return nullptr;
        }

        if (key > node->val) {
            node->right = deleteNodeHelper(node->right, key);
        } else if (key < node->val) {
            node->left = deleteNodeHelper(node->left, key);
        } else {
            TreeNode* merged = merge(node->left, node->right);
            delete node;
            return merged;
        }

        return node;
    }

    TreeNode* merge(TreeNode* left, TreeNode* right) {
        if (!left || !right) {
            return left ? left : right;
        }

        TreeNode* insert = right;
        while (insert->left) {
            insert = insert->left;
        }

        insert->left = left;
        return right;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}