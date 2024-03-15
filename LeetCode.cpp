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
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        deque<TreeNode*> q;
        vector<int> row;

        if (root)
            q.push_back(root);

        bool odd = false;
        while (!q.empty()) {
            int s = q.size();
            odd = !odd;
            row.clear();

            for (; s > 0; --s) {
                TreeNode* node = q.front();
                q.pop_front();
                row.push_back(node->val);
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }

            if (odd) {
                result.push_back(move(row));
            } else {
                result.emplace_back();
                result.back().insert(result.back().end(), row.rbegin(), row.rend());
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
