// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const auto& c1, const auto& c2) {
            return abs(c1[0] - c1[1]) > abs(c2[0] - c2[1]);
        });

        int aCount = costs.size() / 2;
        int bCount = aCount;
        int ans = 0;

        for (auto& cost : costs) {
            if (cost[0] < cost[1] && aCount > 0 || bCount == 0) {
                ans += cost[0];
                --aCount;
            } else {
                ans += cost[1];
                --bCount;
            }
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