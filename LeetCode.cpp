// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 1) { return 0; }

        int n = grid.size();
        int maxN = n * n;
        int minT = max(grid.front().front(), grid.back().back());
        int maxT = maxN - 1;
        vector<char> visited(maxN);

        while (minT <= maxT) {
            memset(visited.data(), 0, sizeof(char) * maxN);
            int midT = (minT + maxT) / 2;

            if (dfs(visited, grid, 0, 0, midT)) {
                maxT = midT - 1;
            } else {
                minT = midT + 1;
            }
        }

        return minT;
    }
private:
    bool dfs(vector<char>& visited, vector<vector<int>>& grid, int row, int col, int t) {
        if (row < 0 || row == grid.size() || col < 0 || col == grid.size() || grid[row][col] > t) { return false; }
        if (row == grid.size() - 1 && col == grid.size() - 1) { return true; }

        if (visited[grid[row][col]]) { return false; }
        visited[grid[row][col]] = 1;

        return dfs(visited, grid, row - 1, col, t) ||
            dfs(visited, grid, row, col + 1, t) ||
            dfs(visited, grid, row + 1, col, t) ||
            dfs(visited, grid, row, col - 1, t);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}