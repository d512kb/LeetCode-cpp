// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n + 1);
        manager[headID] = n;

        for (int i = 0; i < n; ++i) {
            graph[manager[i]].push_back(i);
        }

        return dfs(graph, informTime, headID);
    }
private:
    int dfs(vector<vector<int>>& graph, vector<int>& informTime, int n) {
        int maxTime = 0;
        for (int sub : graph[n]) {
            maxTime = max(maxTime, dfs(graph, informTime, sub));
        }

        return informTime[n] + maxTime;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}