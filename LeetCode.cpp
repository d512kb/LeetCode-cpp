// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<pair<int, int>> sortedIntervals;
        sortedIntervals.reserve(sz);

        for (int i = 0; i < sz; ++i) {
            auto& interval = intervals[i];
            sortedIntervals.emplace_back(interval[0], i);
        }

        sort(sortedIntervals.begin(), sortedIntervals.end());
        vector<int> result;
        result.reserve(sz);

        for (auto& interval : intervals) {
            auto iter = lower_bound(sortedIntervals.begin(), sortedIntervals.end(), interval[1], [](auto& p, int right) { return p.first < right; });

            if (iter != sortedIntervals.end()) {
                result.push_back(iter->second);
            } else {
                result.push_back(-1);
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