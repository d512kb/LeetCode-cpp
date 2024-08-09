// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i < strs.size(); ++i) {
            int bits[2]{ 0 };

            for (char c : strs[i]) {
                ++bits[c - '0'];
            }

            int zeroes = bits[0];
            int ones = bits[1];

            for (int i = m; i >= zeroes; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeroes][j - ones]);
                }
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