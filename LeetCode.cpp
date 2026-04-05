// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;

        for (int i = 2; i < nums.size(); ++i) {
            if (2 * (nums[i - 2] + nums[i]) == nums[i - 1]) {
                ++ans;
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