// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        const size_t sz = nums.size();
        long long totalSubarrays = 1;
        int alternatingLen = 1;

        for (int i = 1; i < sz; ++i) {
            if (nums[i - 1] == nums[i]) {
                alternatingLen = 1;
            } else {
                ++alternatingLen;
            }

            totalSubarrays += alternatingLen;
        }

        return totalSubarrays;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}