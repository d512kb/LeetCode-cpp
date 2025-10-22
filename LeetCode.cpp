// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        partial_sort(nums.begin(), nums.begin() + 2, nums.end(), greater<>{});

        return (nums[0] - 1) * (nums[1] - 1);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}