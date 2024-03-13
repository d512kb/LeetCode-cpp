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
    int sumNumbers(TreeNode* root) {
        sumNumbersHelper(root, 0);

        return m_sum;
    }
private:
    void sumNumbersHelper(TreeNode* node, int number) {
        if (!node)
            return;

        number = number * 10 + node->val;

        if (node->left == nullptr && node->right == nullptr) {
            m_sum += number;
            return;
        }

        sumNumbersHelper(node->left, number);
        sumNumbersHelper(node->right, number);
    }

    int m_sum{ 0 };
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
