// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<char> enters(n, 1);
        vector<char> visited(n);
        vector<char> hasValues(n);
        vector<vector<int>> dp(n, vector<int>(26));

        auto dfs = [&](auto&& dfs, int i) -> bool {
            if (visited[i]) { return false; }
            visited[i] = 1;

            for (int n : graph[i]) {
                if (!hasValues[n]) { if (!dfs(dfs, n)) return false; }
                transform(begin(dp[i]), end(dp[i]), begin(dp[n]), begin(dp[i]), [](int a, int b) { return max(a, b); });
            }

            ++dp[i][colors[i] - 'a'];
            hasValues[i] = 1;

            visited[i] = 0;
            return true;
        };

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            enters[edge[1]] = 0;
        }

        int result = -1;
        for (int i = 0; i < n; ++i) {
            if (enters[i] == 1) {
                if (dfs(dfs, i)) {
                    result = max(result, *max_element(begin(dp[i]), end(dp[i])));
                } else {
                    return -1;
                }
            }
        }

        return find(begin(hasValues), end(hasValues), 0) != end(hasValues) ? -1 : result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}