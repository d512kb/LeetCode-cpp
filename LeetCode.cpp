// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        vector<pair<int, int>> dp(cols + 1);

        for (auto& row : grid) {
            auto prevRow = dp;

            for (int j = 0; j < cols; ++j) {
                char c = row[j];
                auto& currCell = dp[j + 1];
                auto& leftCell = dp[j];
                auto& diagCell = prevRow[j];

                currCell.first += leftCell.first - diagCell.first + (c == 'X');
                currCell.second += leftCell.second - diagCell.second + (c == 'Y');

                if (currCell.first > 0 && currCell.first == currCell.second) {
                    ++result;
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}