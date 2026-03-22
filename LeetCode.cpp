// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        size_t longestDiag = 0;

        for (const auto& dim : dimensions) {
            size_t diag = dim[0] * dim[0] + dim[1] * dim[1];
            if (diag > longestDiag) {
                longestDiag = diag;
                ans = dim[0] * dim[1];
            }
            else if (diag == longestDiag) {
                ans = max(ans, dim[0] * dim[1]);
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