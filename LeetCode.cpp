// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3) { return -1; }

        sort(nums.begin(), nums.begin() + 3);

        return nums[1];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}