// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int sz = bombs.size();
        vector<vector<int>> graph(sz);

        for (int i = 0; i < sz; ++i) {
            const auto& bombA = bombs[i];

            for (int j = i + 1; j < sz; ++j) {
                const auto& bombB = bombs[j];
                double centersDistance = sqrt(pow(bombA[0] - bombB[0], 2) + pow(bombA[1] - bombB[1], 2));

                if (bombA[2] >= centersDistance) { graph[i].push_back(j); }
                if (bombB[2] >= centersDistance) { graph[j].push_back(i); }
            }
        }

        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            vector<char> detonated(sz);
            ans = max(ans, dfs(graph, detonated, i));
        }

        return ans;
    }
private:
    int dfs(const vector<vector<int>>& graph, vector<char>& detonated, int bomb) {
        detonated[bomb] = 1;
        int result = 1;

        for (int b : graph[bomb]) {
            if (detonated[b] == 0) {
                result += dfs(graph, detonated, b);
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