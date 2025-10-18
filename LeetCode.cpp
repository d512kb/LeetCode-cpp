// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> rightSums(nums.size());
        partial_sum(nums.rbegin(), nums.rend() - 1, rightSums.rbegin() + 1);
        int leftSum = 0;

        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(abs(leftSum - rightSums[i]));
            leftSum += nums[i];
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}