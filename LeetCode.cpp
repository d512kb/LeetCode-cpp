// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<short> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], static_cast<short>(1 + dp[i - coin]));
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    vector<int> coins{ 186,419,83,408 };
    int r = sol.coinChange(coins, 6249);

    PRINT_ELAPSED(timer);
    return 0;
}
