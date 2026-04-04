// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m;
        int col = n;

        for (const auto& op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }

        return row * col;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}