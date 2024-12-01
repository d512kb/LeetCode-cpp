// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) { return 0; }

        using Connection = pair<int, pair<int, int>>;
        vector<Connection> graph;
        graph.reserve((points.size() - 1) * points.size() / 2);

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                graph.emplace_back(calcDistance(points[i], points[j]), make_pair(i, j));
            }
        }

        vector<int> pointsChains(points.size());
        iota(pointsChains.begin(), pointsChains.end(), 0);

        auto cmp = [](const Connection& conn1, const Connection& conn2) { return conn1.first > conn2.first; };
        make_heap(graph.begin(), graph.end(), cmp);
        int connections = 0;
        int ans = 0;

        while (connections < points.size() - 1) {
            pop_heap(graph.begin(), graph.end(), cmp);

            auto [p1, p2] = graph.back().second;
            int cost = graph.back().first;
            graph.pop_back();

            while (p1 != pointsChains[p1]) { p1 = pointsChains[p1]; }
            while (p2 != pointsChains[p2]) { p2 = pointsChains[p2]; }

            if (p1 != p2) {
                if (p1 > p2) { swap(p1, p2); }

                pointsChains[p2] = p1;
                ans += cost;
                ++connections;
            }
        }

        return ans;
    }
private:
    inline int calcDistance(const auto& p1, const auto& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}