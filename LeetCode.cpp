// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        const size_t sz = nums.size();
        int dels = 0;

        for (int i = 1; i < sz; ++i) {
            if (nums[i - 1] >= nums[i]) {
                if (++dels > 1) { return false; }

                if (i > 1 && nums[i - 2] >= nums[i]) {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}