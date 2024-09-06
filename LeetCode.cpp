// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int colSz = grid[0].size();
        int col = 0;
        int row = grid.size() - 1;
        int ans = 0;

        while (row >= 0 && col < colSz) {
            if (grid[row][col] < 0) {
                ans += colSz - col;
                --row;
            } else {
                ++col;
            }
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}