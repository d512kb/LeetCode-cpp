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
        if (head == nullptr)
            return nullptr;

        Node* h = head;
        while (h) {
            Node* newNode = new Node(h->val);
            newNode->next = h->next;
            h->next = newNode;
            h = newNode->next;
        }

        h = head;
        while (h) {
            h->next->random = h->random ? h->random->next : nullptr;
            h = h->next->next;
        }

        Node* newHead = new Node(0);
        Node* nh = newHead;

        while (head) {
            nh->next = head->next;
            nh = nh->next;
            head->next = nh->next;

            head = head->next;
        }

        nh = newHead->next;
        delete newHead;

        return nh;
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
