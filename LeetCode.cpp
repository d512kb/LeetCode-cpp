// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        const int maxN = 100;
        vector<vector<char>> graph(n);

        for (auto& v : redEdges) { graph[v[0]].push_back(v[1]); }
        for (auto& v : blueEdges) { graph[v[0]].push_back(-v[1]); }

        queue<char> q;
        q.push(0);
        int depth = -1;
        bitset<maxN * 2 + 1> visited;
        vector<int> result(n, -1);

        while (!q.empty()) {
            ++depth;
            int sz = q.size();

            while (sz--) {
                char from = q.front();
                visited[from + maxN] = 1;
                char nodeIndex = abs(from);
                q.pop();

                if (result[nodeIndex] == -1) {
                    result[nodeIndex] = depth;
                }

                for (int to : graph[nodeIndex]) {
                    if (!visited[to + maxN] && to * from <= 0) {
                        q.push(to);
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}