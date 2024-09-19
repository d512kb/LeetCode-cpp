// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> result;
        vector<vector<char>> dp(rows, vector<char>(cols));
        char dirs[]{ -1, 0, 1, 0, -1 };
        queue<tuple<int, int, char>> q;

        for (int row = 0; row < rows; ++row) {
            q.emplace(row, -1, 0b01);
            q.emplace(row, cols, 0b10);
        }
        for (int col = 0; col < cols; ++col) {
            q.emplace(-1, col, 0b01);
            q.emplace(rows, col, 0b10);
        }

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [row, col, ocean] = q.front();
                q.pop();
                int height = 0;

                if (row >= 0 && row < rows && col >= 0 && col < cols) { height = heights[row][col]; }

                for (int i = 0; i < 4; ++i) {
                    int newRow = row + dirs[i];
                    int newCol = col + dirs[i + 1];

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        if (dp[newRow][newCol] & ocean) { continue; }

                        if (height <= heights[newRow][newCol]) {
                            q.emplace(newRow, newCol, ocean);
                            dp[newRow][newCol] |= ocean;

                            if (dp[newRow][newCol] == 0b11) { result.push_back({ newRow, newCol }); }
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}