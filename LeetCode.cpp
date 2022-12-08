// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a binary tree node.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> backtrace;
        vector<int> leaves;
        leaves.reserve(200);

        while (root1 != nullptr) {
            if (root1->right != nullptr) {
                backtrace.push(root1->right);
            }

            if (root1->left != nullptr) {
                root1 = root1->left;
                continue;
            }
            
            if (root1->right == nullptr) {
                leaves.push_back(root1->val);
            }

            if (backtrace.empty()) {
                root1 = nullptr;
            } else {
                root1 = backtrace.top();
                backtrace.pop();
            }
        }

        int leafIndex = 0;

        while (root2 != nullptr) {
            if (root2->right != nullptr) {
                backtrace.push(root2->right);
            }

            if (root2->left != nullptr) {
                root2 = root2->left;
                continue;
            }

            if (root2->right == nullptr) {
                if (leafIndex == leaves.size() || leaves[leafIndex++] != root2->val) {
                    return false;
                }
            }

            if (backtrace.empty()) {
                root2 = nullptr;
            } else {
                root2 = backtrace.top();
                backtrace.pop();
            }
        }

        return leafIndex == leaves.size();
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    PRINT_ELAPSED(timer);

    return 0;
}
