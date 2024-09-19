// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        char dirs[]{ -1, 0, 1, 0, -1 };
        int result = 0;

        for (int row = 1; row < rows - 1; ++row) {
            for (int col = 1; col < cols - 1; ++col) {
                if (grid[row][col]) {
                    int cells = 1;
                    grid[row][col] = 0;

                    if (dfs(grid, row, col, rows, cols, cells)) {
                        result += cells;
                    }
                }
            }
        }

        return result;
    }
private:
    bool dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int& cells) {
        char dirs[]{ -1, 0, 1, 0, -1 };
        bool inside = true;

        for (int i = 0; i < 4; ++i) {
            int newRow = row + dirs[i];
            int newCol = col + dirs[i + 1];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (grid[newRow][newCol] == 0) { continue; }
                grid[newRow][newCol] = 0;
                ++cells;
                inside &= dfs(grid, newRow, newCol, rows, cols, cells);
            } else {
                inside = false;
            }
        }

        return inside;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}