// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = buildTreeStructure(head);

        ListNode* node = head;
        fillTree(root, node);

        return root;
    }
private:
    TreeNode* buildTreeStructure(ListNode* head) {
        if (!head) { return nullptr; }

        TreeNode* tree = new TreeNode();
        queue<TreeNode**> q{ {&tree->left, &tree->right} };

        head = head->next;
        while (head) {
            TreeNode* newNode = new TreeNode();
            *q.front() = newNode;
            q.pop();
            q.push(&newNode->left);
            q.push(&newNode->right);
            head = head->next;
        }

        return tree;
    }

    void fillTree(TreeNode* root, ListNode*& node) {
        if (!root || !node) { return; }

        fillTree(root->left, node);
        root->val = node->val;
        node = node->next;
        fillTree(root->right, node);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}