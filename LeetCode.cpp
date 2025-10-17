// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
    int xorSum(const vector<int>& nums, int index, int currentSum) {
        if (index == nums.size()) { return currentSum; }

        int with = xorSum(nums, index + 1, currentSum ^ nums[index]);
        int without = xorSum(nums, index + 1, currentSum);

        return with + without;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return xorSum(nums, 0, 0);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}