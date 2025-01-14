// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size() + 1);

        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        int64_t cost = 0;

        auto calcSubtree = [&](auto&& self, int prev, int from) -> int {
            int subcitiesCount = 0;

            for (int city : graph[from]) {
                if (city == prev) { continue; }
                subcitiesCount += self(self, from, city);
            }

            cost += ceil((1.0 + subcitiesCount) / seats);
            return 1 + subcitiesCount;
        };

        for (int city : graph[0]) {
            calcSubtree(calcSubtree, 0, city);
        }

        return cost;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}