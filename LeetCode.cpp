// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* preParent = new TreeNode(0);
        parseRightSubTree(preParent, nums, 0, nums.size() - 1);

        TreeNode* node = preParent->right;
        delete preParent;

        return node;
    }
private:
    void parseLeftSubTree(TreeNode* parent, vector<int>& nums, int l, int r) {
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        parent->left = node;

        if (mid != l) parseLeftSubTree(node, nums, l, mid - 1);
        if (mid != r) parseRightSubTree(node, nums, mid + 1, r);
    }
    void parseRightSubTree(TreeNode* parent, vector<int>& nums, int l, int r) {
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        parent->right = node;

        if (mid != l) parseLeftSubTree(node, nums, l, mid - 1);
        if (mid != r) parseRightSubTree(node, nums, mid + 1, r);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
