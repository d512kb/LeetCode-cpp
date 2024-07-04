// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.begin(), nums.end());

        for (int i = 1, j = 0, mx = 0, sz = nums.size(); i < sz; ++i) {
            int& currVal = nums[i];

            if (nums[i - 1] == currVal) {
                dp[i] = currVal + dp[i - 1];
            } else {
                for (; nums[j] + 1 < currVal; ++j) {
                    mx = max(mx, dp[j]);
                }
                dp[i] = currVal + mx;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}