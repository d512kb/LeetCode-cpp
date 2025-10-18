// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> result;

        for (int row = 1; row < n - 1; ++row) {
            result.emplace_back();

            for (int col = 1; col < n - 1; ++col) {
                int maxVal = 0;

                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        maxVal = max(maxVal, grid[row + i][col + j]);
                    }
                }

                result.back().push_back(maxVal);
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}