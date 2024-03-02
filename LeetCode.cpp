// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> nodeCache;
        unordered_map<int, Node*> newNodes;
        Node* headNew = new Node(0);
        Node* n = headNew;
        int nodeIndex = 0;

        Node* h = head;
        while (h) {
            nodeCache[h] = nodeIndex++;
            h = h->next;
        }

        nodeIndex = 0;

        while (head) {
            auto& newNode = newNodes[nodeIndex++];
            n->next = newNode == nullptr ? new Node(head->val) : newNode;
            n = n->next;
            newNode = n;

            if (head->random) {
                auto& newRandom = newNodes[nodeCache[head->random]];
                n->random = newRandom == nullptr ? new Node(head->random->val) : newRandom;
                newRandom = n->random;
            }

            head = head->next;
        }

        n = headNew->next;
        delete headNew;

        return n;
    }
};

int main() {
    INIT_TIME(timer);
        
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next = n2;
    n1->random = n2;
    n2->random = n2;

    Solution sol;
    auto node = sol.copyRandomList(n1);

    PRINT_ELAPSED(timer);
    return 0;
}
