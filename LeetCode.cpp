// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        const int sz = nums.size();
        vector<int64_t> dp(sz);
        vector<int> monoStack;
        int64_t sumMin = 0, sumMax = 0;

        for (int i = 0; i < sz; ++i) {
            while (!monoStack.empty() && nums[monoStack.back()] >= nums[i]) {
                monoStack.pop_back();
            }

            if (monoStack.empty()) {
                dp[i] = static_cast<int64_t>(i + 1) * nums[i];
            } else {
                int j = monoStack.back();
                dp[i] = dp[j] + static_cast<int64_t>(i - j) * nums[i];
            }

            monoStack.push_back(i);
            sumMin += dp[i];
        }

        monoStack.clear();

        for (int i = 0; i < sz; ++i) {
            while (!monoStack.empty() && nums[monoStack.back()] <= nums[i]) {
                monoStack.pop_back();
            }

            if (monoStack.empty()) {
                dp[i] = static_cast<int64_t>(i + 1) * nums[i];
            } else {
                int j = monoStack.back();
                dp[i] = dp[j] + static_cast<int64_t>(i - j) * nums[i];
            }

            monoStack.push_back(i);
            sumMax += dp[i];
        }

        return sumMax - sumMin;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}