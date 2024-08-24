// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        char visited[m][n];
        memset(&visited, 0, sizeof(visited));
        visited[entrance[0]][entrance[1]] = 1;

        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        char dirs[]{ -1, 0, 1, 0, -1 };
        int result = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int newRow = row + dirs[i];
                    int newCol = col + dirs[i + 1];

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol] && maze[newRow][newCol] == '.') {
                        if (newRow == 0 || newRow == m - 1 || newCol == 0 || newCol == n - 1) {
                            return result;
                        }

                        visited[newRow][newCol] = 1;
                        q.emplace(newRow, newCol);
                    }
                }
            }

            ++result;
        }

        return -1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}