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
    void flatten(TreeNode* root) {
        TreeNode* preRoot = new TreeNode(0);
        TreeNode* preRootPtr = preRoot;

        flattenHelper(root, preRoot);
        setRight(root);

        delete preRootPtr;
    }
    
    void flattenIter(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* tmp = cur->left;
                while (tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }

    TreeNode* prev = nullptr;
    void flattenRecurFast(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
private:
    void flattenHelper(TreeNode* root, TreeNode*& prev) {
        if (!root)
            return;

        prev->left = root;
        prev = root;

        flattenHelper(root->left, prev);
        flattenHelper(root->right, prev);
    }

    void setRight(TreeNode* root) {
        if (!root)
            return;

        setRight(root->left);

        root->right = root->left;
        root->left = nullptr;
    }
};

int main() {
    INIT_TIME(timer);

    TreeNode root[]{0,1,2,3,4,5,6};
    root[1].left = &root[2];
    root[1].right = &root[5];
    root[2].left = &root[3];
    root[2].right = &root[4];
    root[5].right = &root[6];
    
    Solution sol;
    sol.flatten(&root[1]);

    PRINT_ELAPSED(timer);
    return 0;
}
