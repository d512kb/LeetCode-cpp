// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;

        unordered_map<int, int> numsCount;

        for (int right = 0; right < nums.size(); ++right) {
            int& count = numsCount[nums[right]];
            ++count;

            while (count > k) {
                --numsCount[nums[left++]];
            }

            ans = max(ans, right - left + 1);
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