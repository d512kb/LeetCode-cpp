// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });

        int a = 0;
        int b = 0;

        while (a < intervals.size()) {
            int maxRight = intervals[a][1];

            while (b < intervals.size() - 1 && intervals[b + 1][0] <= maxRight) {
                ++b;
                maxRight = max(maxRight, intervals[b][1]);
            }

            result.push_back({ intervals[a][0], maxRight });
            a = b = b + 1;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    vector<vector<int>> v {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    sol.merge(v);

    PRINT_ELAPSED(timer);
    return 0;
}
