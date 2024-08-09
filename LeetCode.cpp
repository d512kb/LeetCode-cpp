// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            int64_t sum = 0;

            for (int n : nums) {
                if (n <= i) {
                    sum += dp[i - n];
                }
            }

            dp[i] = sum;
        }

        return dp[target];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}