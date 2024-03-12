// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
 
class Solution {
public:
    Node* connect(Node* root) {
        Node* preHead = new Node();
        Node* prev = preHead;
        Node* node = root;

        while (node) {
            if (node->left) {
                prev->next = node->left;
                prev = node->left;
            }
            if (node->right) {
                prev->next = node->right;
                prev = node->right;
            }
            node = node->next;

            if (!node) {
                node = preHead->next;
                preHead->next = nullptr;
                prev = preHead;
            }
        }

        delete preHead;

        return root;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
