// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        pair<int, int> startPoint;
        bitset<32> keysAvailable = 1 << 31;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char ch = grid[i][j];

                if (ch == '@') {
                    startPoint = { i, j };
                } else if (ch >= 'a' && ch <= 'z') {
                    keysAvailable.set(ch - 'a');
                }
            }
        }

        queue<tuple<int, int, bitset<32>>> q({ {startPoint.first, startPoint.second, 1 << 31} });
        vector<vector<bitset<32>>> visited(rows, vector<bitset<32>>(cols));
        const char dirs[]{ -1, 0, 1, 0, -1 };
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            ++steps;

            while (sz--) {
                auto [row, col, keys] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int newRow = row + dirs[i];
                    int newCol = col + dirs[i + 1];
                    auto newKeys = keys;

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        if ((visited[newRow][newCol] & keys) == keys) { continue; }
                        int ch = grid[newRow][newCol];

                        if (ch == '#' || (ch >= 'A' && ch <= 'Z' && !keys[ch - 'A'])) { continue; }
                        if (ch >= 'a' && ch <= 'z') {
                            newKeys |= 1 << ch - 'a';

                            if (newKeys == keysAvailable) { return steps; }
                        }

                        q.emplace(newRow, newCol, newKeys);
                        visited[newRow][newCol] = newKeys;
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