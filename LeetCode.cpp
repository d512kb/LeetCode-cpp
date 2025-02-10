// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Cell {
        int row{};
        int col{};
        int cost{};
    };
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int rows = grid.size();
        const int cols = grid.front().size();
        const char dirs[]{ 1, 0, -1, 0, 1 };

        vector<vector<int>> visited(rows, vector<int>(cols, numeric_limits<int>::max()));
        visited[0][0] = grid[0][0];
        deque<Cell> dq;
        dq.emplace_front(0, 0, grid[0][0]);

        while (!dq.empty()) {
            const auto [row, col, cost] = dq.front();
            dq.pop_front();

            if (row == rows - 1 && col == cols - 1) { return cost < health; }

            for (int i = 0; i < 4; ++i) {
                const int newRow = row + dirs[i];
                const int newCol = col + dirs[i + 1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int travelCost = cost + grid[newRow][newCol];

                    if (travelCost < visited[newRow][newCol]) {
                        visited[newRow][newCol] = travelCost;

                        if (grid[newRow][newCol] == 1) {
                            dq.emplace_back(newRow, newCol, travelCost);
                        } else {
                            dq.emplace_front(newRow, newCol, travelCost);
                        }
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}