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
    vector<int> preorder(Node* root) {
        if (!root) { return {}; }

        stack<Node*> st({ root });
        vector<int> result;

        while (!st.empty()) {
            auto node = st.top();
            st.pop();

            result.push_back(node->val);

            for (auto childIter = node->children.rbegin(), end = node->children.rend(); childIter != end; ++childIter) {
                st.push(*childIter);
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}