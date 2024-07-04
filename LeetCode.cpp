// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rowSz = matrix.front().size();
        vector<vector<int>> dp(2, vector<int>(rowSz, 0));
        auto readRowIter = dp.begin();
        auto writeRowIter = next(dp.begin());

        for (auto& row : matrix) {
            for (int i = 0; i < rowSz; ++i) {
                auto& readRow = *readRowIter;
                auto& writeRow = *writeRowIter;

                int a = readRow[max(0, i - 1)];
                int b = readRow[i];
                int c = readRow[min(rowSz - 1, i + 1)];

                writeRow[i] = row[i] + min({ a, b, c });
            }

            swap(readRowIter, writeRowIter);
        }

        return *min_element(readRowIter->begin(), readRowIter->end());
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}