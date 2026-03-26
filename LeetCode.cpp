// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        auto check = [&](int row, int col) {
            int ans = 0;

            if (grid[row][col] == 'W') { ++ans; }
            if (grid[row][col + 1] == 'W') { ++ans; }
            if (grid[row + 1][col] == 'W') { ++ans; }
            if (grid[row + 1][col + 1] == 'W') { ++ans; }

            return ans != 2;
            };

        return check(0, 0) || check(0, 1) || check(1, 0) || check(1, 1);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}