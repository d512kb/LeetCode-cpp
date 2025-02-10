// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Cell {
        int row{};
        int col{};
        int cost{};

        bool operator>(const Cell& other) const {
            return cost > other.cost;
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int rows = heights.size();
        const int cols = heights.front().size();
        const char dirs[]{ 1, 0, -1, 0, 1 };

        vector<vector<int>> visited(rows, vector<int>(cols, numeric_limits<int>::max()));
        visited[0][0] = 0;
        priority_queue<Cell, vector<Cell>, greater<>> pq;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            const auto [row, col, cost] = pq.top();
            pq.pop();

            if (row == rows - 1 && col == cols - 1) { return cost; }

            for (int i = 0; i < 4; ++i) {
                const int newRow = row + dirs[i];
                const int newCol = col + dirs[i + 1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    const int effort = max(cost, abs(heights[row][col] - heights[newRow][newCol]));

                    if (effort < visited[newRow][newCol]) {
                        visited[newRow][newCol] = effort;
                        pq.emplace(newRow, newCol, effort);
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