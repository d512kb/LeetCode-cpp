// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int cameraCount = 0;

        if (traverseTree(root, cameraCount) > 1) { ++cameraCount; }

        return cameraCount;
    }
private:
    int traverseTree(TreeNode* root, int& cameraCount) {
        if (!root) { return 1; }

        int leftChild = traverseTree(root->left, cameraCount);
        int rightChild = traverseTree(root->right, cameraCount);

        if (leftChild > 1 || rightChild > 1) {
            ++cameraCount;
            return 0;
        }

        return 1 + min(leftChild, rightChild);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}