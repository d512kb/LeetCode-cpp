// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// non-recursive solution
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) { return {}; }

        list<Node*> lst{ root };
        queue<list<Node*>::iterator> q;
        q.push(lst.begin());

        while (!q.empty()) {
            auto iter(std::move(q.front()));
            q.pop();

            for (auto child : (*iter)->children) {
                q.push(lst.insert(iter, child));
            }
        }

        vector<int> result;
        transform(lst.begin(), lst.end(), back_inserter(result), [](const Node* ptr) { return ptr->val; });

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}