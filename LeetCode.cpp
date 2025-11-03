// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int len = nums[0] % 2 == 0 && nums[0] <= threshold;
        int ans = len;

        for (int i = 1; i < nums.size(); ++i) {
            if (((nums[i - 1] ^ nums[i]) & 1) && nums[i - 1] <= threshold && nums[i] <= threshold) {
                ++len;
            }
            else {
                len = nums[i] % 2 == 0 && nums[i] <= threshold;
            }

            ans = max(ans, len);
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