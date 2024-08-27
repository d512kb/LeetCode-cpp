// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);

        if (target % 2) {
            return false;
        }

        target /= 2;
        bitset<20000 + 1> dp(1);

        for (int n : nums) {
            dp |= dp << n;
        }

        return dp[target];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}