// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, char> intCounts;
        int intSum = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid.size(); ++col) {
                ++intCounts[grid[row][col]];
                intSum += grid[row][col];
            }
        }

        vector<int> result{ 0, 0 };

        for (const auto& [val, count] : intCounts) {
            if (count == 2) { result[0] = val; break; }
        }

        int n = grid.size() * grid.size();

        result[1] = (n * (n + 1) / 2) - (intSum - result[0]);

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}