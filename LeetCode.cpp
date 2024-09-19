// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                result = max(result, getIslandArea(grid, row, col));
            }
        }

        return result;
    }
private:
    int getIslandArea(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || grid[row][col] == 0) { return 0; }
        grid[row][col] = 0;

        return 1 + getIslandArea(grid, row - 1, col) + getIslandArea(grid, row, col + 1) +
            getIslandArea(grid, row + 1, col) + getIslandArea(grid, row, col - 1);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}