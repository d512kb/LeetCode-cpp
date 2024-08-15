// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = 0;

        map<vector<int>, int> mp;

        for (auto& row : grid) {
            ++mp[row];
        }

        for (int i = 0; i < n; ++i) {
            vector<int> col(n);

            for (int j = 0; j < n; ++j) {
                col[j] = grid[j][i];
            }

            auto iter = mp.find(col);
            if (iter != mp.end()) {
                result += iter->second;
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