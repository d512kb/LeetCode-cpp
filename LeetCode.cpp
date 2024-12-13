// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int sz = grid.size();
        vector<vector<int>> islands(sz, vector<int>(sz));
        vector<int> islandsSizes{ 0 };
        char dirs[]{ 1, 0, -1, 0, 1 };

        auto discoverIsland = [&](auto&& self, int row, int col, int islandNumber) -> int {
            if (row < 0 || row == sz || col < 0 || col == sz || !grid[row][col] || islands[row][col]) { return 0; }

            islands[row][col] = islandNumber;
            return 1 + self(self, row - 1, col, islandNumber) +
                self(self, row, col + 1, islandNumber) +
                self(self, row + 1, col, islandNumber) +
                self(self, row, col - 1, islandNumber);
        };

        for (int row = 0; row < sz; ++row) {
            for (int col = 0; col < sz; ++col) {
                if (grid[row][col] && !islands[row][col]) {
                    int islandNumber = islandsSizes.size();
                    islandsSizes.push_back(discoverIsland(discoverIsland, row, col, islandNumber));
                }
            }
        }

        int ans = 0;

        for (int row = 0; row < sz; ++row) {
            for (int col = 0; col < sz; ++col) {
                if (islands[row][col] == 0) {
                    map<int, int> islandsNear;

                    for (int i = 0; i < 4; ++i) {
                        int newRow = row + dirs[i];
                        int newCol = col + dirs[i + 1];

                        if (newRow >= 0 && newRow < sz && newCol >= 0 && newCol < sz) {
                            int islandNumber = islands[newRow][newCol];
                            islandsNear.emplace(islandNumber, islandsSizes[islandNumber]);
                        }
                    }

                    ans = max(ans, accumulate(islandsNear.begin(), islandsNear.end(), 1, [](int a, const auto& p) { return a + p.second; }));
                }
            }
        }

        return max(ans, *max_element(islandsSizes.begin(), islandsSizes.end()));
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}