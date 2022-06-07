// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;


// Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<pair<TreeNode *, bool>> backTrace;
        TreeNode *currentNode = root;

        if (currentNode == nullptr)
            return result;

        do {
            result.push_back(currentNode->val);

            if (currentNode->left != nullptr) {
                backTrace.push(make_pair(currentNode, true));
                currentNode = currentNode->left;
                continue;
            }

            if (currentNode->right != nullptr) {
                backTrace.push(make_pair(currentNode, false));
                currentNode = currentNode->right;
                continue;
            }

            while (!backTrace.empty()) {
                auto &trace = backTrace.top();

                if (trace.second == true && trace.first->right != nullptr) {
                    currentNode = trace.first->right;
                    trace.second = false;
                    break;
                }

                backTrace.pop();
            }
        } while (!backTrace.empty());

        return result;
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<pair<TreeNode *, bool>> backTrace;
        TreeNode *currentNode = root;

        if (currentNode == nullptr)
            return result;

        do {
            if (currentNode->left != nullptr) {
                backTrace.push(make_pair(currentNode, true));
                currentNode = currentNode->left;
                continue;
            }

            result.push_back(currentNode->val);

            if (currentNode->right != nullptr) {
                backTrace.push(make_pair(currentNode, false));
                currentNode = currentNode->right;
                continue;
            }

            while (!backTrace.empty()) {
                auto &trace = backTrace.top();

                if (trace.second == true) {
                    result.push_back(trace.first->val);

                    if (trace.first->right != nullptr) {
                        currentNode = trace.first->right;
                        trace.second = false;
                        break;
                    }
                }

                backTrace.pop();
            }
        } while (!backTrace.empty());

        return result;
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<pair<TreeNode *, bool>> backTrace;
        TreeNode *currentNode = root;

        if (currentNode == nullptr)
            return result;

        do {
            if (currentNode->left != nullptr) {
                backTrace.push(make_pair(currentNode, true));
                currentNode = currentNode->left;
                continue;
            }

            if (currentNode->right != nullptr) {
                backTrace.push(make_pair(currentNode, false));
                currentNode = currentNode->right;
                continue;
            }

            result.push_back(currentNode->val);

            while (!backTrace.empty()) {
                auto &trace = backTrace.top();

                if (trace.second == true && trace.first->right != nullptr) {
                    currentNode = trace.first->right;
                    trace.second = false;
                    break;
                }

                result.push_back(trace.first->val);
                backTrace.pop();
            }
        } while (!backTrace.empty());

        return result;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        stack<pair<TreeNode *, bool>> backTrace;
        TreeNode *currentNode = root;
        int level = 0;

        if (currentNode == nullptr)
            return result;

        do {
            if (result.size() <= level) {
                result.emplace_back();
            }
            result[level].push_back(currentNode->val);

            if (currentNode->left != nullptr) {
                backTrace.push(make_pair(currentNode, true));
                currentNode = currentNode->left;
                ++level;
                continue;
            }

            if (currentNode->right != nullptr) {
                backTrace.push(make_pair(currentNode, false));
                currentNode = currentNode->right;
                ++level;
                continue;
            }

            while (!backTrace.empty()) {
                auto &trace = backTrace.top();

                if (trace.second && trace.first->right != nullptr) {
                    currentNode = trace.first->right;
                    trace.second = false;
                    break;
                }

                backTrace.pop();
                --level;
            }
        } while (!backTrace.empty());

        return result;
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    bool isSymmetric(TreeNode *root) {
        return isMirrored(root->left, root->right);
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root)
            return hasPathSumRecursive(root, targetSum);
        else
            return false;
    }

private:
    bool isMirroredRecursive(TreeNode *left, TreeNode *right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }

        if (left->val != right->val) {
            return false;
        }

        return isMirroredRecursive(left->left, right->right) && isMirroredRecursive(left->right, right->left);
    }
    bool isMirrored(TreeNode *left, TreeNode *right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }

        stack<pair<TreeNode *, bool>> backTraceLeft, backTraceRight; // trace right has opposite bool meaning

        do {
            if (left->val != right->val)
                return false;

            if (left->left && right->right) {
                backTraceLeft.push(make_pair(left, true));
                backTraceRight.push(make_pair(right, true));
                left = left->left;
                right = right->right;
                continue;
            }

            if (left->left != right->right) { return false; }

            if (left->right && right->left) {
                backTraceLeft.push(make_pair(left, false));
                backTraceRight.push(make_pair(right, false));
                left = left->right;
                right = right->left;
                continue;
            }

            if (left->right != right->left) { return false; }

            while (!backTraceLeft.empty() && !backTraceRight.empty()) {
                auto &traceLeft = backTraceLeft.top();
                auto &traceRight = backTraceRight.top();
                bool leftSecondSubtree = false, rightSecondSubtree = false;

                if (traceLeft.second && traceLeft.first->right) {
                    left = traceLeft.first->right;
                    traceLeft.second = false;
                    leftSecondSubtree = true;
                }
                
                if (traceRight.second && traceRight.first->left) {
                    right = traceRight.first->left;
                    traceRight.second = false;
                    rightSecondSubtree = true;
                }

                if (leftSecondSubtree && rightSecondSubtree) {
                    break;
                }

                if (leftSecondSubtree || rightSecondSubtree) {
                    return false;
                }

                backTraceLeft.pop();
                backTraceRight.pop();
            }
        } while (!backTraceLeft.empty() && !backTraceRight.empty());

        return backTraceLeft.size() == backTraceRight.size();
    }
    bool hasPathSumRecursive(TreeNode *root, int targetSum) {
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        bool hasSum = false;

        if (root->left) {
            hasSum = hasPathSumRecursive(root->left, targetSum - root->val);
        }

        if (root->right) {
            hasSum |= hasPathSumRecursive(root->right, targetSum - root->val);
        }

        return hasSum;
    }
};

int main() {
    TreeNode root(1), right1(2), left2(2);
    root.right = &right1;
    root.left = &left2;

    Solution sol;
    sol.maxDepth(&root);
    sol.isSymmetric(&root);

    return 0;
}
