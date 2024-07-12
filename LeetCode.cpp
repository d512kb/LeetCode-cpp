// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int offset = 30;
        vector<int> dp(365 + offset);

        auto daysIter = days.begin();
        int dayCost = costs[0];
        int weekCost = costs[1];
        int monthCost = costs[2];

        for (int i = 1, dpIndex = offset, day = *daysIter; i <= 365; ++i, ++dpIndex) {
            if (i == day) {
                dp[dpIndex] = min(min(dayCost + dp[dpIndex - 1], weekCost + dp[dpIndex - 7]), monthCost + dp[dpIndex - 30]);
                if (++daysIter == days.end()) {
                    return dp[dpIndex];
                }
                day = *daysIter;
            } else {
                dp[dpIndex] = dp[dpIndex - 1];
            }
        }

        return 0;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}