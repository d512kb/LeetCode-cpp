// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        int islands = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    deque<pair<int, int>> cells;
                    cells.emplace_back(i, j);
                    grid[i][j] = '0';
                    ++islands;

                    while (!cells.empty()) {
                        int c = cells.size();

                        for (; c > 0; --c) {
                            auto [i, j] = cells.front();
                            cells.pop_front();

                            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                                cells.emplace_back(i - 1, j);
                                grid[i - 1][j] = '0';
                            }
                            if (i + 1 < rows && grid[i + 1][j] == '1') {
                                cells.emplace_back(i + 1, j);
                                grid[i + 1][j] = '0';
                            }
                            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                                cells.emplace_back(i, j - 1);
                                grid[i][j - 1] = '0';
                            }
                            if (j + 1 < cols && grid[i][j + 1] == '1') {
                                cells.emplace_back(i, j + 1);
                                grid[i][j + 1] = '0';
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
