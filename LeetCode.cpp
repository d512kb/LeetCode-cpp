// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        traverseTree(root, target, k, result);

        return result;
    }
private:
    int traverseTree(TreeNode* node, TreeNode* target, int k, vector<int>& values) {
        if (!node) { return 500; }
        if (node == target) {
            gatherValues(node, k, values);
            return 1;
        }

        int leftDistance = traverseTree(node->left, target, k, values);
        int rightDistance = traverseTree(node->right, target, k, values);

        if (leftDistance == k || rightDistance == k) { values.push_back(node->val); }
        else if (leftDistance < k) { gatherValues(node->right, k - leftDistance - 1, values); }
        else if (rightDistance < k) { gatherValues(node->left, k - rightDistance - 1, values); }

        return 1 + min(leftDistance, rightDistance);
    }

    void gatherValues(TreeNode* node, int k, vector<int>& values) {
        if (!node) { return; }

        if (k == 0) {
            values.push_back(node->val);
            return;
        }

        gatherValues(node->left, k - 1, values);
        gatherValues(node->right, k - 1, values);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}