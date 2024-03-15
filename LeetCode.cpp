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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> items;
        helper(root, k, items);
        return items.back();
    }
private:
    bool helper(TreeNode* node, int k, vector<int>& items) {
        if (!node)
            return false;

        if (helper(node->left, k, items))
            return true;

        items.push_back(node->val);
        if (items.size() == k)
            return true;

        return helper(node->right, k, items);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
