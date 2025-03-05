// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, pair<int, int>> playerStats;

        for (const auto& match : matches) {
            ++playerStats[match[0]].first; // actually we don't need win count
            ++playerStats[match[1]].second;
        }

        vector<vector<int>> result(2);

        for (const auto& [playerId, stats] : playerStats) {
            if (stats.second == 0) {
                result[0].push_back(playerId);
            } else if (stats.second == 1) {
                result[1].push_back(playerId);
            }
        }

        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}