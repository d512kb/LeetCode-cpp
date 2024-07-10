// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            int trees = 0;

            for (int j = 1; j <= i; ++j) {
                trees += dp[j - 1] * dp[i - j];
            }

            dp[i] = trees;
        }

        return dp.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}