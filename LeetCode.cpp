// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> rangeCount(52);

        for (const auto& r : ranges) {
            ++rangeCount[r[0]];
            --rangeCount[r[1] + 1];
        }

        for (int i = 1; i < rangeCount.size(); ++i) {
            rangeCount[i] += rangeCount[i - 1];
        }

        for (left; left <= right; ++left) {
            if (rangeCount[left] <= 0) { return false; }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}