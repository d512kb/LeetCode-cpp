// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int g = grid[i][j];

                if (g == 2) {
                    q.emplace(i, j);
                } else if (g == 1) {
                    ++fresh;
                }
            }
        }

        char dirs[]{ -1, 0, 1, 0, -1 };
        int result = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int newRow = row + dirs[i];
                    int newCol = col + dirs[i + 1];

                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) {
                        continue;
                    }

                    if (grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.emplace(newRow, newCol);
                        --fresh;
                    }
                }
            }

            result += !q.empty();
        }

        return fresh > 0 ? -1 : result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}