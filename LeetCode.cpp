// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        const int sz = nums.size();
        sort(nums.begin(), nums.end());

        int medianIndex = sz / 2;
        long long ans = 0;

        if (k < nums[medianIndex]) { // decrease left part
            for (; medianIndex >= 0 && nums[medianIndex] > k; --medianIndex) {
                ans += nums[medianIndex] - k;
            }
        } else if (k > nums[medianIndex]) { // increase right part
            for (; medianIndex < sz && nums[medianIndex] < k; ++medianIndex) {
                ans += k - nums[medianIndex];
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}