// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        map<pair<int, int>, int> richCells;
        vector<pair<int, int>> poorCells;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[i][j];
                if (val > 1) {
                    richCells.emplace(make_pair(i, j), val - 1);
                } else if (val == 0) {
                    poorCells.emplace_back(i, j);
                }
            }
        }

        int ans = numeric_limits<int>::max();

        auto perm = [&](auto&& self, int permIndex, int moves) {
            if (permIndex == poorCells.size()) {
                ans = min(ans, moves);
                return;
            }

            for (auto& [cell, value] : richCells) {
                if (value > 0) {
                    --value;
                    self(self, permIndex + 1, moves + abs(cell.first - poorCells[permIndex].first) + abs(cell.second - poorCells[permIndex].second));
                    ++value;
                }
            }
        };

        perm(perm, 0, 0);

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}