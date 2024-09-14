// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) { return -1; }

        int lastRow = grid.size() - 1;
        int lastCol = grid[0].size() - 1;
        int len = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty()) {
            int sz = q.size();
            ++len;

            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                if (row == lastRow && col == lastCol) { return len; }

                for (int r = -1; r <= 1; ++r) {
                    for (int c = -1; c <= 1; ++c) {
                        int newRow = row + r;
                        int newCol = col + c;

                        if (newRow >= 0 && newRow <= lastRow && newCol >= 0 && newCol <= lastCol) {
                            int& val = grid[newRow][newCol];

                            if (val == 0) {
                                val = 1;
                                q.emplace(newRow, newCol);
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}