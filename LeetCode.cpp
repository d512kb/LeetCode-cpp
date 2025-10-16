// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) { return 0; }

        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto node = q.front();
                q.pop();

                if (!node->left && !node->right) { return ans; }
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }

            ++ans;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);
 
    PRINT_ELAPSED(timer);
    return 0;
}