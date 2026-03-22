// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            uint64_t gcdArr = nums[i];
            uint64_t lcmArr = nums[i];
            uint64_t prodArr = nums[i];

            for (int j = i + 1; j < nums.size(); ++j) {
                gcdArr = gcd(gcdArr, nums[j]);
                lcmArr = lcm(lcmArr, nums[j]);
                prodArr *= nums[j];

                if (prodArr == gcdArr * lcmArr) { ans = max(ans, j - i + 1); }
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}