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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int s = q.size();
            double sum = 0;

            for (int i = 0; i < s; ++i) {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }

            result.push_back(sum / s);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
