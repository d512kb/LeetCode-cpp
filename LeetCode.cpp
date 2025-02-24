// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto commonParent = findCommonParent(root, startValue, destValue);

        string path, startPath, destPath;
        buildPath(commonParent, startValue, path, startPath);
        buildPath(commonParent, destValue, path, destPath);

        return string(startPath.size(), 'U') + destPath;
    }
private:
    TreeNode* findCommonParent(TreeNode* node, int startValue, int destValue) {
        if (!node) { return nullptr; }
        if (node->val == startValue || node->val == destValue) { return node; }

        auto leftPart = findCommonParent(node->left, startValue, destValue);
        auto rightPart = findCommonParent(node->right, startValue, destValue);

        if (leftPart && rightPart) { return node; }
        return leftPart ? leftPart : rightPart ? rightPart : nullptr;
    }

    void buildPath(TreeNode* node, int value, string& path, string& finalPath) {
        if (!node) { return; }
        if (node->val == value) { finalPath = path; return; }

        path.push_back('L');
        buildPath(node->left, value, path, finalPath);
        path.back() = 'R';
        buildPath(node->right, value, path, finalPath);
        path.pop_back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}