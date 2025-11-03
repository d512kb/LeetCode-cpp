// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int len = 1;
        int longestLen = 1;
        int sign = 1;

        for (int i = 0; i < nums.size() - 1; ) {
            if (nums[i] + sign == nums[i + 1]) {
                sign = -sign;
                longestLen = max(longestLen, ++len);
                ++i;
            }
            else {
                if (sign == 1) {
                    len = 1;
                    ++i;
                }
                else {
                    len = 1;
                    sign = -sign;
                }
            }
        }

        return longestLen == 1 ? -1 : longestLen;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}