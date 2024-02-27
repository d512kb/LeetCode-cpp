// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return { {newInterval[0], newInterval[1]} };

        auto bIter = lower_bound(intervals.begin(), intervals.end(), newInterval[1], [](const auto& a, const auto& b) {
            return a[1] < b;
        });

        auto aIter = lower_bound(intervals.begin(), bIter, newInterval[0], [](const auto& a, const auto& b) {
            return a[1] < b;
        });

        vector<vector<int>> result;

        move(intervals.begin(), aIter, back_inserter(result));

        const int newA = aIter == intervals.end() ? newInterval[0] : min(aIter->front(), newInterval[0]);
        const int& newB = newInterval[1];

        if (bIter == intervals.end() || newB < bIter->front()) {
            result.push_back({ newA, newB });
            aIter = bIter;
        } else {
            result.push_back({ newA, bIter->back() });
            aIter = bIter + 1;
        }

        move(aIter, intervals.end(), back_inserter(result));

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
