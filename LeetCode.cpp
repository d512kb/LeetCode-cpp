// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const auto sz = nums.size();
        sort(nums.begin(), nums.end());

        return max(nums[0] * nums[1] * nums[sz - 1], nums[sz - 1] * nums[sz - 2] * nums[sz - 3]);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}