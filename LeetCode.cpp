// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater{});

        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] + nums[i - 1] > nums[i - 2]) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }

        return 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}