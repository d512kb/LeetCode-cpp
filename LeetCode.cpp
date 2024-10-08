// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serialize(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize(data, index);
    }
private:
    void serialize(TreeNode* node, string& to) {
        if (!node) { return; }

        to.push_back(node->val);
        to.push_back(node->val >> 8);

        to.push_back(node->left != nullptr);
        to.push_back(node->right != nullptr);

        serialize(node->left, to);
        serialize(node->right, to);
    }

    TreeNode* deserialize(const string& from, int& index) {
        if (index >= from.size()) { return nullptr; }

        int a = from[index++] & 0xFF;
        int b = from[index++];
        TreeNode* node = new TreeNode(a + (b << 8));

        bool left = from[index++];
        bool right = from[index++];

        if (left) { node->left = deserialize(from, index); }
        if (right) { node->right = deserialize(from, index); }

        return node;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}