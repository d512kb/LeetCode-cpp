// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int, int>> bestBuys(prices.size() + 1, { 0, 0 });

        int maxSum = 0;
        int sum = 0;

        for (int i = 1, sz = prices.size(); i < sz; ++i) {
            sum += prices[i] - prices[i - 1];

            if (sum < 0) {
                sum = 0;
            } else if (sum > maxSum) {
                maxSum = sum;
            }

            bestBuys[i + 1].first = maxSum;
        }

        maxSum = 0;
        sum = 0;

        for (int i = prices.size() - 2; i >= 0; --i) {
            sum += prices[i + 1] - prices[i];

            if (sum < 0) {
                sum = 0;
            } else if (sum > maxSum) {
                maxSum = sum;
            }

            bestBuys[i].second = maxSum;
        }

        auto maxPair = max_element(bestBuys.begin(), bestBuys.end(), [](const auto& p1, const auto& p2) { return p1.first + p1.second < p2.first + p2.second; });

        return maxPair->first + maxPair->second;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}