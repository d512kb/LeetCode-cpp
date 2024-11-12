// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Cell {
        int row;
        int col;
        int time;

        friend bool operator>(const Cell& c1, const Cell& c2) {
            if (c1.time != c2.time) { return c1.time > c2.time; }
            if (c1.row != c2.row) { return c1.row > c2.row; }
            return c1.col > c2.col;
        }
    };
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();

        priority_queue<Cell, vector<Cell>, greater<Cell>> q;
        vector<vector<int>> cellTimes(rows, vector<int>(cols, numeric_limits<int>::max()));
        char dirs[]{ 1, 0, -1, 0, 1 };
        q.emplace(0, 0, 0);

        while (!q.empty()) {
            auto cell = q.top();
            q.pop();

            if (cell.row == rows - 1 && cell.col == cols - 1) { return cell.time; }

            for (int i = 0; i < 4; ++i) {
                int newRow = cell.row + dirs[i];
                int newCol = cell.col + dirs[i + 1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int timeToVisit = 1 + max(cell.time, moveTime[newRow][newCol]);

                    if (timeToVisit < cellTimes[newRow][newCol]) {
                        cellTimes[newRow][newCol] = timeToVisit;
                        q.emplace(newRow, newCol, timeToVisit);
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