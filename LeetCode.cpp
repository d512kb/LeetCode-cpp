// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> players(n, vector<int>(11));

        for (const auto& p : pick) {
            ++players[p[0]][p[1]];
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (any_of(players[i].begin(), players[i].end(), [i](const auto& c) { return c > i; })) {
                ++ans;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}