// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> baloons{ 1 };
        copy(begin(nums), end(nums), back_inserter(baloons));
        baloons.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));

        for (int w = 1; w <= n; ++w) {
            for (int left = 1, right = w; right <= n; ++left, ++right) {
                int maxVal = 0;
                for (int i = left; i <= right; ++i) {
                    maxVal = max(maxVal, baloons[left - 1] * baloons[i] * baloons[right + 1] +
                                 dp[left][i - 1] + dp[i + 1][right]);
                }
                dp[left][right] = maxVal;
            }
        }

        return dp[1][n];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}