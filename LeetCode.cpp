// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;

        buildPathSum(root, paths, path, 0, targetSum);

        return paths;
    }
private:
    void buildPathSum(TreeNode* node, vector<vector<int>>& paths, vector<int>& path, int currentSum, int targetSum) {
        if (!node) { return; }

        currentSum += node->val;
        path.push_back(node->val);
        buildPathSum(node->left, paths, path, currentSum, targetSum);
        buildPathSum(node->right, paths, path, currentSum, targetSum);

        if (!node->left && !node->right && currentSum == targetSum) {
            paths.push_back(path);
        }

        path.pop_back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}