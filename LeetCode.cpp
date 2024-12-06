// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialData;

        serialize(root, serialData);

        return serialData;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize(data, index);
    }

private:
    void serialize(TreeNode* node, string& to) {
        if (!node) {
            to.push_back(static_cast<char>(0xFF));
            return;
        }

        to.push_back(node->val >> 8);
        to.push_back(node->val);

        serialize(node->left, to);
        serialize(node->right, to);
    }

    TreeNode* deserialize(const string& from, int& index) {
        if (index >= from.size()) { return nullptr; }
        if (from[index] == static_cast<char>(0xFF)) {
            ++index;
            return nullptr;
        }

        int a = from[index++];
        int b = static_cast<unsigned char>(from[index++]);
        TreeNode* root = new TreeNode((a << 8) + b);

        root->left = deserialize(from, index);
        root->right = deserialize(from, index);

        return root;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}