// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int sz = nums.size();
        vector<int> dp(sz, -1);
        dp[0] = 0;

        for (int to = 1; to < sz; ++to) {
            for (int from = 0; from < to; ++from) {
                if (dp[from] >= 0 && abs(nums[to] - nums[from]) <= target) {
                    dp[to] = max(dp[to], 1 + dp[from]);
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}