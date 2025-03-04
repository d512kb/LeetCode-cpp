// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> counts(maxCost + 1);

        // counting sort
        for (int cost : costs) { ++counts[cost]; }
        partial_sum(counts.begin(), counts.end(), counts.begin());

        vector<int> sortedCosts(costs.size());

        for (int i = costs.size() - 1; i >= 0; --i) {
            sortedCosts[counts[costs[i]]-- - 1] = costs[i];
        }

        int ans = 0;
        for (int cost : sortedCosts) {
            coins -= cost;
            if (coins < 0) { break; }
            ++ans;
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