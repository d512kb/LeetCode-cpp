// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        auto sortedUntil = is_sorted_until(nums.begin(), nums.end(), less_equal{});
        int ans = distance(nums.begin(), sortedUntil);
        if (ans == nums.size()) { --ans; } // we need this in case the array is sorted to correct last increase

        for (int i = nums.size() - 1; i > 0; --i) {
            if (i < nums.size() - 1 && nums[i] >= nums[i + 1]) { break; }
            sortedUntil = upper_bound(nums.begin(), sortedUntil, nums[i] - 1);

            // add length of the prefix that can be joined with the suffix, and also add the case when there is
            // something in between to remove
            ans += distance(nums.begin(), sortedUntil) + (distance(nums.begin(), sortedUntil) != i);
        }

        return ans + 1; // + case when we remove all the items
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}