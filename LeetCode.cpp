// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int sz = nums.size();
        int64_t prefixMax = nums.front();
        int64_t maxDiff = -1;
        int64_t ans = -1;

        for (int j = 1; j < sz - 1; ++j) {
            maxDiff = max(maxDiff, prefixMax - nums[j]);
            ans = max(ans, maxDiff * nums[j + 1]);
            prefixMax = max<int64_t>(prefixMax, nums[j]);
        }

        return ans < 0 ? 0 : ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}