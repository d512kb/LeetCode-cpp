// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int64_t dp0 = nums[0];
        int64_t dp1 = dp0;

        for (int i = 1, sz = nums.size(); i < sz; ++i) {
            int64_t oldDp = dp0;
            dp0 = max(dp0, dp1) + nums[i];
            dp1 = oldDp - nums[i];
        }

        return max(dp0, dp1);
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}