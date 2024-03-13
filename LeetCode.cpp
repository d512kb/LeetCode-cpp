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
 
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root)
            saveTree(root);
    }

    int next() {
        TreeNode* node = m_backTrack.back();
        m_backTrack.pop_back();
        if (node->right)
            saveTree(node->right);
        return node->val;
    }

    bool hasNext() {
        return !m_backTrack.empty();
    }
private:
    void saveTree(TreeNode* node) {
        while (node) {
            m_backTrack.push_back(node);
            node = node->left;
        }
    }

    vector<TreeNode*> m_backTrack;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
