// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();

        vector<int> dpRow(n, 0);
        vector<vector<int>> dp(m, dpRow);

        for (int i = 0, ob = 0; i < m; ++i) {
            if (!ob && obstacleGrid[i][0]) { ob = 1; }
            dp[i][0] = !ob;
        }

        for (int j = 0, ob = 0; j < n; ++j) {
            if (!ob && obstacleGrid[0][j]) { ob = 1; }
            dp[0][j] = !ob;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
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
