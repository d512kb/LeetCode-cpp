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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexes;

        for (int i = 0; i < inorder.size(); ++i) {
            indexes[inorder[i]] = i;
        }

        auto iter = preorder.begin();
        return buildTreeHelper(iter, indexes, 0, inorder.size());
    }
private:
    TreeNode* buildTreeHelper(vector<int>::iterator& pIter, const unordered_map<int, int>& indexes, int from, int to) {
        if (from == to)
            return nullptr;

        int itemIndex = indexes.at(*pIter);
        TreeNode* parent = new TreeNode(*pIter++);

        parent->left = buildTreeHelper(pIter, indexes, from, itemIndex);
        parent->right = buildTreeHelper(pIter, indexes, ++itemIndex, to);

        return parent;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
