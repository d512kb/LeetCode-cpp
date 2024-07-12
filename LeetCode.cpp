// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            int minVal = n;

            for (int s = 1, m = 1; s <= i; ++m, s = m * m) {
                minVal = min(minVal, 1 + dp[i - s]);
            }

            dp[i] = minVal;
        }

        return dp.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}