// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        const int sz = nums.size();

        array<int, 4> items{};

        nth_element(nums.begin(), nums.begin(), nums.end());
        items[0] = nums[0];
        nth_element(nums.begin(), nums.begin() + 1, nums.end());
        items[1] = nums[1];
        nth_element(nums.begin(), nums.end() - 1, nums.end());
        items[2] = nums[sz - 1];
        nth_element(nums.begin(), nums.end() - 2, nums.end());
        items[3] = nums[sz - 2];

        return ((items[2] * items[3]) - (items[0] * items[1]));
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}