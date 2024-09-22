// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cityRoads(n);
        vector<vector<char>> roadMap(n, vector<char>(n));

        for (auto& r : roads) {
            int c1 = r[0];
            int c2 = r[1];

            ++cityRoads[c1];
            ++cityRoads[c2];

            roadMap[c1][c2] = 1;
            roadMap[c2][c1] = 1;
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                result = max(result, cityRoads[i] + cityRoads[j] - roadMap[i][j]);
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