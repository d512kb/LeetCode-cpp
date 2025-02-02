// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        array<char, 10> numCounts{};
        int pathCount = 0;

        traverseTree(root, numCounts, pathCount);

        return pathCount;
    }
private:
    void traverseTree(TreeNode* node, array<char, 10>& numCounts, int& pathCount) {
        if (!node) { return; }

        ++numCounts[node->val];

        if (node->left || node->right) {
            traverseTree(node->left, numCounts, pathCount);
            traverseTree(node->right, numCounts, pathCount);
        } else {
            int oddCount = 0;
            for (char c : numCounts) {
                if (c % 2) { ++oddCount; }
            }

            if (oddCount <= 1) { ++pathCount; }
        }

        --numCounts[node->val];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}