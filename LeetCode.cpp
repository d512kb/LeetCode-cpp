// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;

        for (int i = 0; i < graph.size(); ++i) {
            if (isSafeNode(graph, i)) {
                result.push_back(i);
            }
        }

        return result;
    }
private:
    bool isSafeNode(vector<vector<int>>& graph, int node) {
        if (m_safeNodes[node] || m_visitedNodes[node]) { return m_safeNodes[node]; }
        if (graph[node].empty()) { return m_safeNodes[node] = 1; }

        m_visitedNodes[node] = 1;

        for (int n : graph[node]) {
            if (!isSafeNode(graph, n)) { return false; }
        }

        return m_safeNodes[node] = 1;
    }

    bitset<10001> m_safeNodes;
    bitset<10001> m_visitedNodes;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}