// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for (int row = 0; row < rows; ++row) {
            if (!q.empty()) { break; }

            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    mapIsland(grid, row, col, rows, cols, q);
                    break;
                }
            }
        }

        char dirs[]{ -1, 0, 1, 0, -1 };
        int len = 0;

        while (!q.empty()) {
            int sz = q.size();
            ++len;

            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int newRow = row + dirs[i];
                    int newCol = col + dirs[i + 1];

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        int& val = grid[newRow][newCol];

                        if (val == 1) { return len - 1; }
                        if (val == 0) {
                            val = 2;
                            q.emplace(newRow, newCol);
                        }
                    }
                }
            }
        }

        return len;
    }
private:
    void mapIsland(vector<vector<int>>& grid, int row, int col, int rows, int cols, queue<pair<int, int>>& q) {
        q.emplace(row, col);
        grid[row][col] = 2;
        char dirs[]{ -1, 0, 1, 0, -1 };

        for (int i = 0; i < 4; ++i) {
            int newRow = row + dirs[i];
            int newCol = col + dirs[i + 1];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (grid[newRow][newCol] == 1) {
                    mapIsland(grid, newRow, newCol, rows, cols, q);
                }
            }
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}