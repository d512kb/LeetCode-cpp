// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int sz = b.size();
        vector<int64_t> dp(sz + 1);

        for (int aIndex = 1; aIndex <= 4; ++aIndex) {
            int64_t aVal = a[aIndex - 1];
            int64_t prev = dp[aIndex - 1];
            dp[aIndex] = aVal * b[aIndex - 1] + exchange(prev, dp[aIndex]);

            for (int bIndex = aIndex + 1; bIndex <= sz; ++bIndex) {
                dp[bIndex] = max(dp[bIndex - 1], aVal * b[bIndex - 1] + exchange(prev, dp[bIndex]));
            }
        }

        return dp.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}