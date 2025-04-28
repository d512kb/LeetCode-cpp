// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        constexpr int N = 10;
        const int rows = grid.size();
        const int cols = grid.front().size();

        vector<pair<int, char>> dpPrev(N), dp(N);

        for (int col = 0; col < cols; ++col) {
            swap(dpPrev, dp);
            array<int, N> nCount{};

            for (int row = 0; row < rows; ++row) {
                ++nCount[grid[row][col]];
            }

            for (int val = 0; val < N; ++val) {
                dp[val].second = val;
                dp[val].first = rows - nCount[val];

                if (dpPrev.front().second != val) {
                    dp[val].first += dpPrev.front().first;
                } else {
                    dp[val].first += next(dpPrev.begin())->first;
                }
            }

            sort(dp.begin(), dp.end());
        }

        return dp.front().first;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}