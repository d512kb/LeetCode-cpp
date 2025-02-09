// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int sz = grid.size();

        for (int colInit = sz - 1; colInit > 0; --colInit) {
            vector<int> values;

            for (int row = 0, col = colInit; col < sz; ++row, ++col) {
                values.push_back(grid[row][col]);
            }

            sort(values.begin(), values.end());

            for (int row = 0, col = colInit; col < sz; ++row, ++col) {
                grid[row][col] = values[row];
            }
        }

        for (int rowInit = 0; rowInit < sz; ++rowInit) {
            vector<int> values;

            for (int row = rowInit, col = 0; row < sz; ++row, ++col) {
                values.push_back(grid[row][col]);
            }

            sort(values.begin(), values.end(), greater<>{});

            for (int row = rowInit, col = 0; row < sz; ++row, ++col) {
                grid[row][col] = values[col];
            }
        }

        return grid;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}