// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int rows = calcHeight(root);
        int cols = (1 << rows) - 1;

        vector<vector<string>> result(rows, vector<string>(cols));

        printTree(root, 0, 0, cols, result);

        return result;
    }
private:
    int calcHeight(TreeNode* node) {
        if (!node) { return 0; }

        return 1 + max(calcHeight(node->left), calcHeight(node->right));
    }

    void printTree(TreeNode* node, int level, int begin, int end, vector<vector<string>>& output) {
        if (!node) { return; }
        int midPoint = (begin + end) / 2;

        output[level][midPoint] = to_string(node->val);

        printTree(node->left, level + 1, begin, midPoint, output);
        printTree(node->right, level + 1, midPoint, end, output);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}