// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    function<bool(int, int)> m_lessPred = less<int>();
    function<bool(int, int)> m_greaterPred = greater<int>();
public:
    void recoverTree(TreeNode* root) {
        if (!root) { return; }

        auto leftWrongChild = findWrongChild(root, root->val, root->left, m_lessPred);
        auto rightWrongChild = findWrongChild(root, root->val, root->right, m_greaterPred);

        if (leftWrongChild && rightWrongChild) {
            swap(leftWrongChild->val, rightWrongChild->val);
            return;
        }

        if (leftWrongChild) {
            swap(root->val, leftWrongChild->val);
            return;
        }

        if (rightWrongChild) {
            swap(root->val, rightWrongChild->val);
            return;
        }

        recoverTree(root->left);
        recoverTree(root->right);
    }

private:
    template<typename Pr>
    TreeNode* findWrongChild(TreeNode* root, int bestVal, TreeNode* node, const Pr& pred) {
        if (!node) { return nullptr; }
        TreeNode* result = nullptr;

        if (!pred(node->val, bestVal)) {
            bestVal = node->val;
            result = node;
        }

        auto child = findWrongChild(root, bestVal, node->left, pred);
        if (child) {
            bestVal = child->val;
            result = child;
        }

        child = findWrongChild(root, bestVal, node->right, pred);

        return child ? child : result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}