// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int drops = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                ++drops;
            }
        }

        return drops == 0 || (drops == 1 && nums.front() >= nums.back());
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}