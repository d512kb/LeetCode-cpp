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
        unordered_map<Node*, Node*> nodesMap;

        Node* h = head;
        while (h) {
            nodesMap[h] = new Node(h->val);
            h = h->next;
        }

        h = head;

        while (h) {
            auto& node = nodesMap[h];
            node->next = nodesMap[h->next];
            node->random = nodesMap[h->random];

            h = h->next;
        }

        return nodesMap[head];
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
