// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int secondMin = findSecondMin(root, root->val);

        return secondMin != 0 ? secondMin : -1;
    }
private:
    int findSecondMin(TreeNode* node, int firstMin) {
        if (!node) { return 0; }
        if (node->val > firstMin) { return node->val; }

        int a = findSecondMin(node->left, firstMin);
        int b = findSecondMin(node->right, firstMin);

        if (a == 0 || b == 0) { return a + b; }
        return min(a, b);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}