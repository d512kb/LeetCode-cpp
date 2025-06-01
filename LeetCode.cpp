// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const auto rows = grid.size();
        const auto cols = grid[0].size();

        vector<vector<int>> result(rows - k + 1, vector<int>(cols - k + 1));

        for (int rowStart = 0; rowStart <= rows - k; ++rowStart) {
            for (int colStart = 0; colStart <= cols - k; ++colStart) {
                vector<int> values;
                values.reserve(k * k);

                for (int i = rowStart; i < rowStart + k; ++i) {
                    for (int j = colStart; j < colStart + k; ++j) {
                        values.push_back(grid[i][j]);
                    }
                }

                sort(values.begin(), values.end());
                int minDiff = numeric_limits<int>::max();

                for (auto iter = values.begin(), nextIter = next(iter); nextIter != values.end(); ++iter, ++nextIter) {
                    if (*iter != *nextIter) {
                        minDiff = min(minDiff, abs(*iter - *nextIter));
                    }
                }

                result[rowStart][colStart] = minDiff == numeric_limits<int>::max() ? 0 : minDiff;
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