// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        constexpr int modulo = 1e9 + 7;
        vector<vector<int>> graph(edges.size() + 2);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(graph.size());
        visited[1] = true;

        int maxPath = getMaxPathLength(graph, visited, 1);

        return fastExp(2, maxPath - 1, modulo);
    }

private:
    int getMaxPathLength(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
        int maxPath = 0;

        for (int child : graph[node]) {
            if (visited[child]) { continue; }
            visited[child] = true;

            maxPath = max(maxPath, 1 + getMaxPathLength(graph, visited, child));
        }

        return maxPath;
    }

    int fastExp(int64_t base, int64_t exp, int modulo) {
        int64_t ans = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % modulo;
            }

            base = (base * base) % modulo;
            exp /= 2;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}