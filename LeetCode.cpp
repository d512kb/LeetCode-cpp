// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<char> rowsIncremented(m), colsIncremented(n);

        for (const auto& ind : indices) {
            ++rowsIncremented[ind[0]];
            ++colsIncremented[ind[1]];
        }

        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += (rowsIncremented[i] + colsIncremented[j]) & 1;
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