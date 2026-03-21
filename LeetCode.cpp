// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid.front().size();

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                if (row < rows - 1 && grid[row][col] != grid[row + 1][col]) { return false; }
                if (col < cols - 1 && grid[row][col] == grid[row][col + 1]) { return false; }
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}