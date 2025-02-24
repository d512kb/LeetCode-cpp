// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    using TreeHash = string;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<TreeHash, int> hashCount;
        vector<TreeNode*> result;

        calcTreeHashes(root, hashCount, result);
        return result;
    }
private:
    TreeHash calcTreeHashes(TreeNode* node, unordered_map<TreeHash, int>& hashCount, vector<TreeNode*>& result) {
        if (!node) { return "#"; }

        auto leftSubtree(std::move(calcTreeHashes(node->left, hashCount, result)));
        auto rightSubtree(std::move(calcTreeHashes(node->right, hashCount, result)));

        auto treeHash = to_string(node->val) + ',' + leftSubtree + ',' + rightSubtree;
        if (++hashCount[treeHash] == 2) {
            result.push_back(node);
        }

        return treeHash;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}