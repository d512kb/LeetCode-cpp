// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        unordered_map<Node*, Node*> mapping;
        Node* result = new Node(node->val);
        mapping.emplace(node, result);

        deque<Node*> q;
        q.push_back(node);

        while (!q.empty()) {
            int s = q.size();

            for (; s > 0; --s) {
                node = q.front();
                q.pop_front();

                for (Node* n : node->neighbors) {
                    auto iter = mapping.find(n);

                    if (iter == mapping.end()) {
                        iter = mapping.emplace(n, new Node(n->val)).first;
                        q.push_back(n);
                    }

                    mapping[node]->neighbors.push_back(iter->second);
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    Node nodes[]{ 0,1,2,3,4 };
    nodes[1].neighbors.assign({ &nodes[2], &nodes[4] });
    nodes[2].neighbors.assign({ &nodes[1], &nodes[3] });
    nodes[3].neighbors.assign({ &nodes[2], &nodes[4] });
    nodes[4].neighbors.assign({ &nodes[1], &nodes[3] });

    Solution sol;
    auto cl = sol.cloneGraph(&nodes[1]);

    PRINT_ELAPSED(timer);
    return 0;
}
