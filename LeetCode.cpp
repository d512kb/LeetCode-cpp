// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

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
    TreeNode* generateTree(int n) {
        TreeNode* left, *right, *node;
        left = right = node = nullptr;
        
        for (size_t i = 0; i < n; ++i) {
            switch (i % 3) {
            case 0:
                left = new TreeNode(i, node, nullptr);
                break;
            case 1:
                right = new TreeNode(-i);
                break;
            case 2:
                node = new TreeNode(i / 2, left, right);
            default:
                break;
            }
        }

        switch (n % 3) {
        case 0:
            return node;
        case 1:
            return left;
        case 2:
            delete right;
            return left;
        default:
            return node;
            break;
        }

        return node;
    }

    int maxPathSum(TreeNode* root) {
        vector<TreeNode*> backtrack;
        vector<TreeNode*> backtree;

        TreeNode* node = root;

        while (node != nullptr) {
            backtree.push_back(node);

            if (node->right != nullptr) {
                backtrack.push_back(node->right);
            }

            if (node->left != nullptr) {
                node = node->left;
                continue;
            }

            if (!backtrack.empty()) {
                node = backtrack.back();
                backtrack.pop_back();
            } else {
                node = nullptr;
            }
        }

        int maxSum = numeric_limits<int>::min();

        while (!backtree.empty()) {
            node = backtree.back();
            backtree.pop_back();

            if (node->left == nullptr) {
                if (node->right != nullptr) {
                    node->val += node->right->val > 0 ? node->right->val : 0;
                }
            } else {
                if (node->right == nullptr) {
                    node->val += node->left->val > 0 ? node->left->val : 0;
                } else {
                    auto maxVal = max(node->left->val, node->right->val);
                    maxSum = max({ maxSum, node->val, node->val + maxVal, node->val + node->left->val + node->right->val });
                    node->val += maxVal > 0 ? maxVal : 0;
                }
            }

            maxSum = max(maxSum, node->val);
        }

        return maxSum;
    }
    int maxPathSumRecurr(TreeNode* root) {
        int maxSum = root->val;
        maxPathSumR(root, maxSum);
        return maxSum;
    }
private:
    int maxPathSumR(TreeNode* node, int& maxSum) {
        if (node != nullptr) {
            int leftVal = maxPathSumR(node->left, maxSum);
            int rightVal = maxPathSumR(node->right, maxSum);
            int maxVal = max(leftVal, rightVal);

            maxSum = max({ maxSum, node->val, node->val + maxVal, node->val + leftVal + rightVal });
            
            return maxVal > 0 ? node->val + maxVal : node->val;
        }

        return 0;
    }
};

int main() {
    Solution sol;

    TreeNode* root;
    root = sol.generateTree(100000);

    INIT_TIME(timer);

    //root = new TreeNode(5,
    //                    new TreeNode(9),
    //                    new TreeNode(-4,
    //                                 new TreeNode(2,
    //                                              new TreeNode(20),
    //                                              nullptr),
    //                                 new TreeNode(-2,
    //                                              new TreeNode(20),
    //                                              new TreeNode(20))));

    cout << sol.maxPathSum(root) << endl;

    PRINT_ELAPSED(timer);

    return 0;
}
