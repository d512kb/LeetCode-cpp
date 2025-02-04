// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix.front().size();
        int ans = 0;

        if (rows == 1) { return count(matrix[0].begin(), matrix[0].end(), 1); }

        for (int row = 1; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 1) {
                    matrix[row][col] = 1 + matrix[row - 1][col];
                }
            }
        }

        for (auto& row : matrix) {
            sort(row.begin(), row.end(), greater<>());

            for (int i = 0; i < cols; ++i) {
                ans = max(ans, row[i] * (i + 1));
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}