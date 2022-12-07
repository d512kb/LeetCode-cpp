// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <limits>

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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        uint64_t result{ 0 };
        rangeSumBSTRecur(root, low, high, result);
        return result;
    }
private:
    void rangeSumBSTRecur(TreeNode* root, int low, int high, uint64_t& result)
    {
        if (root == nullptr)
            return;
        
        if (root->val >= low && root->val <= high)
            result += root->val;

        if (root->val >= high)
            rangeSumBSTRecur(root->left, low, high, result);
        else if (root->val <= low)
            rangeSumBSTRecur(root->right, low, high, result);
        else
        {
            rangeSumBSTRecur(root->left, low, high, result);
            rangeSumBSTRecur(root->right, low, high, result);
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = { 2,5,3,9,5,3 };
    vector<int> nums2 = { 0 };
    vector<int> nums3 = { 1,2,3,4,5 };

    INIT_TIME(timer);

    PRINT_ELAPSED(timer);

    return 0;
}
