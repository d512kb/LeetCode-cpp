// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLen = nums.size() + 1;

        for (int i = 0; i < nums.size(); ++i) {
            int len = 0;
            int val = 0;

            for (int j = i; j < nums.size(); ++j) {
                val |= nums[j];
                ++len;

                if (val >= k) {
                    minLen = min(minLen, len);
                    break;
                }
            }
        }

        return minLen > nums.size() ? -1 : minLen;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}