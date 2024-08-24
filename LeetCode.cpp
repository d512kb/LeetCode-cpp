// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, char>>> adj(n);
        vector<char> visited(n);

        for (auto& v : connections) {
            int from = v[0];
            int to = v[1];

            adj[from].push_back({ to, 1 });
            adj[to].push_back({ from, 0 });
        }

        queue<int> q({ 0 });
        int result = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            visited[i] = 1;

            for (auto& n : adj[i]) {
                if (visited[n.first]) {
                    continue;
                }

                result += n.second;
                q.push(n.first);
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