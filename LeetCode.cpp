// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;

        vector<int> prefixSum(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), prefixSum.begin() + 1);

        for (int i = 0; i < nums.size(); ++i) {
            ans += prefixSum[i + 1] - prefixSum[max(0, i - nums[i])];
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