// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) { return nullptr; }

        connect(root->left);
        connect(root->right);

        connectBranches(root->left, root->right);

        return root;
    }
private:
    void connectBranches(Node* left, Node* right) {
        if (!left) { return; }

        left->next = right;
        connectBranches(left->right, right->left);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}