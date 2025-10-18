// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            if (nums[start] + nums[end] < target) {
                ans += end - start;
                ++start;
            }
            else {
                --end;
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