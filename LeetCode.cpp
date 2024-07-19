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
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> currentPath;
        vector<vector<TreeNode*>> paths;

        calcPaths(root, currentPath, paths);
        int sz = paths.size();
        int result = 0;

        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                auto& path1 = paths[i];
                auto& path2 = paths[j];

                auto mism = mismatch(path1.begin(), path1.end(), path2.begin());

                if (std::distance(mism.first, path1.end()) + std::distance(mism.second, path2.end()) <= distance) {
                    ++result;
                }
            }
        }

        return result;
    }

private:
    void calcPaths(TreeNode* node, vector<TreeNode*>& currentPath, vector<vector<TreeNode*>>& paths) {
        if (!node)
            return;

        currentPath.push_back(node);

        if (!node->left && !node->right) {
            paths.emplace_back(currentPath.begin(), currentPath.end());
        } else {
            calcPaths(node->left, currentPath, paths);
            calcPaths(node->right, currentPath, paths);
        }

        currentPath.pop_back();
    }
};

int main() {
    INIT_TIME(timer);

    TreeNode nodes[]{ TreeNode(0), TreeNode(1), TreeNode(2), TreeNode(3), TreeNode(4) };

    nodes[1].left = &nodes[2];
    nodes[1].right = &nodes[3];
    nodes[2].right = &nodes[4];

    Solution sol;
    sol.countPairs(&nodes[1], 3);

    PRINT_ELAPSED(timer);
    return 0;
}