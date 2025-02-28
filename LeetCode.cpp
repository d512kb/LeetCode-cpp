// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid.front().size();

        vector<vector<int>> result(rows, vector<int>(cols));

        for (int row = 0; row < rows; ++row) {
            int onesRow = 0;
            int zerosRow = 0;

            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) { ++onesRow; } else { ++zerosRow; }
            }

            for (int col = 0; col < cols; ++col) {
                result[row][col] += onesRow - zerosRow;
            }
        }

        for (int col = 0; col < cols; ++col) {
            int onesCol = 0;
            int zerosCol = 0;

            for (int row = 0; row < rows; ++row) {
                if (grid[row][col] == 1) { ++onesCol; } else { ++zerosCol; }
            }

            for (int row = 0; row < rows; ++row) {
                result[row][col] += onesCol - zerosCol;
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