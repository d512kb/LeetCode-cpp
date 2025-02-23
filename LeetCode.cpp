// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        const int rows = grid.size();
        vector<int> allItems;

        for (int row = 0; row < rows; ++row) {
            auto& gridRow = grid[row];
            partial_sort(gridRow.begin(), gridRow.begin() + limits[row], gridRow.end(), greater<>{});
            copy(gridRow.begin(), gridRow.begin() + limits[row], back_inserter(allItems));
        }

        sort(allItems.begin(), allItems.end(), greater<>{});
        return accumulate(allItems.begin(), allItems.begin() + k, 0l);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}