// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Travel {
        int place;
        int cost;
        int stops;
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights) { graph[f[0]].emplace_back(f[1], f[2]); }

        vector<int> costs(n, numeric_limits<int>::max());
        queue<Travel> pq;
        pq.emplace(src, 0, 0);

        while (!pq.empty()) {
            auto [place, cost, stops] = pq.front();
            pq.pop();

            if (place == dst) { continue; }
            if (stops++ > k) { continue; }

            for (auto& dest : graph[place]) {
                int destCost = cost + dest.second;

                if (destCost < costs[dest.first]) {
                    costs[dest.first] = destCost;
                    pq.emplace(dest.first, destCost, stops);
                }
            }
        }

        return costs[dst] != numeric_limits<int>::max() ? costs[dst] : -1;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}