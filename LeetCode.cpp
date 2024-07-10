// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;


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
    vector<TreeNode*> generateTrees(int n) {
        return genTrees(1, n);
    }
private:
    vector<TreeNode*> genTrees(int from, int to) {
        if (from > to)
            return { nullptr };

        if (from == to) {
            return { new TreeNode(from) };
        }

        vector<TreeNode*> result;

        for (int i = from; i <= to; ++i) {
            auto leftTrees = genTrees(from, i - 1);
            auto rightTrees = genTrees(i + 1, to);

            int ltsz = leftTrees.size();
            int rtsz = rightTrees.size();

            for (int lt = 0; lt < ltsz; ++lt) {
                for (int rt = 0; rt < rtsz; ++rt) {
                    result.push_back(new TreeNode(i, copyTree(leftTrees[lt]), copyTree(rightTrees[rt])));
                }
            }

            for_each(leftTrees.begin(), leftTrees.end(), deleteTree);
            for_each(rightTrees.begin(), rightTrees.end(), deleteTree);
        }

        return result;
    }

    static TreeNode* copyTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        return new TreeNode(root->val, copyTree(root->left), copyTree(root->right));
    }

    static void deleteTree(TreeNode* root) {
        if (!root) {
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}