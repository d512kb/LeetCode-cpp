// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct CellVisit {
        int row{};
        int col{};
        int visitCost{};
    };
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid.front().size();
        const char dirs[]{ 1, 0, -1, 0, 1 };

        vector<vector<int>> visited(rows, vector<int>(cols, numeric_limits<int>::max()));
        visited[0][0] = 0;
        deque<CellVisit> dq;
        dq.emplace_front(0, 0, 0);

        while (!dq.empty()) {
            auto [row, col, visitCost] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int newRow = row + dirs[i];
                int newCol = col + dirs[i + 1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int moveCost = visitCost + grid[newRow][newCol];

                    if (moveCost < visited[newRow][newCol]) {
                        visited[newRow][newCol] = moveCost;

                        if (grid[newRow][newCol] == 1) {
                            dq.emplace_back(newRow, newCol, moveCost);
                        } else {
                            dq.emplace_front(newRow, newCol, moveCost);
                        }
                    }
                }
            }
        }

        return visited.back().back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}