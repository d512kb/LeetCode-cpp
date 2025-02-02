// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;

        dfs(root, start, ans);

        return ans;
    }
private:
    int dfs(TreeNode* node, int start, int& result) {
        if (!node) { return 0; }

        int left = dfs(node->left, start, result);
        int right = dfs(node->right, start, result);

        if (node->val == start) {
            result = max(left, right);
            return -1;
        }

        if (left >= 0 && right >= 0) {
            return max(left, right) + 1;
        }

        result = max(result, abs(left) + abs(right));
        return min(left, right) - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}