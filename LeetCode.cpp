// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k = min(k, static_cast<int>(prices.size() / 2));
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));

        for (int i = 1; i <= k; ++i) {
            int bestSell = -prices[0];
            for (int j = 1, sz = prices.size(); j < sz; ++j) {
                dp[i][j] = max(dp[i][j - 1], bestSell + prices[j]);
                bestSell = max(bestSell, dp[i - 1][j] - prices[j]);
            }
        }

        return dp.back().back();
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}