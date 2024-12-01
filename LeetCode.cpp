// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& time : times) { graph[time[0]].emplace_back(time[2], time[1]); }

        vector<int> costs(n + 1, numeric_limits<int>::max());
        costs[0] = 0; // unused
        costs[k] = 0; // start
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            for (auto& n : graph[p.second]) {
                int travelCost = p.first + n.first;

                if (travelCost < costs[n.second]) {
                    costs[n.second] = travelCost;
                    pq.emplace(travelCost, n.second);
                }
            }
        }

        int ans = *max_element(costs.begin(), costs.end());

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}