// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) { return true; }
        if (!root1 || !root2) { return false; }

        if (root1->val != root2->val) { return false; }

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || 
            (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}