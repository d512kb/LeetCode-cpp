// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    if (traverseLand(grid, row, col, rows, cols)) {
                        ++result;
                    }
                }
            }
        }

        return result;
    }
private:
    bool traverseLand(vector<vector<int>>& grid, int row, int col, int rows, int cols) {
        if (row < 0 || row == rows || col < 0 || col == cols) { return false; }
        if (grid[row][col] == 1) { return true; }

        grid[row][col] = 1;

        bool result = true;
        result &= traverseLand(grid, row - 1, col, rows, cols);
        result &= traverseLand(grid, row, col + 1, rows, cols);
        result &= traverseLand(grid, row + 1, col, rows, cols);
        result &= traverseLand(grid, row, col - 1, rows, cols);

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}