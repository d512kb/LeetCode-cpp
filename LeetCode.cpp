// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int lowest = nums.front();
        int highest = lowest;

        for (int n : nums) {
            lowest = min(lowest, n);
            highest = max(highest, n);
        }

        int maxDiff = highest - lowest;
        vector<vector<int>> dp(nums.size(), vector<int>(maxDiff * 2 + 1, 1));
        int result = 0;

        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j] + maxDiff;
                int currDiff = dp[j][diff] + 1;

                dp[i][diff] = currDiff;

                result = max(result, currDiff);
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