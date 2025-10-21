// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int sz = mat.size();
        int ans = 0;

        for (int row = 0, col = 0; row < sz; ++row, ++col) {
            ans += mat[row][col];
        }

        for (int row = 0, col = sz - 1; row < sz; ++row, --col) {
            ans += mat[row][col];
        }

        if (mat.size() % 2) { ans -= mat[sz / 2][sz / 2]; }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}