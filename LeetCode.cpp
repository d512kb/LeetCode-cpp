// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        char dirs[]{ -1, 0, 1, 0, -1 };
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    for (int i = 0; i < 4; ++i) {
                        int newRow = row + dirs[i];
                        int newCol = col + dirs[i + 1];

                        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                            ++result;
                        } else if (grid[newRow][newCol] == 0) {
                            ++result;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}