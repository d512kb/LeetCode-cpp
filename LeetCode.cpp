// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int windowSize = accumulate(nums.begin(), nums.end(), 0);
        int ones = accumulate(nums.begin(), nums.begin() + windowSize, 0);
        int sz = nums.size();
        int maxOnes = ones;

        for (int a = 0, b = windowSize; b < sz + windowSize - 1; ++a, ++b) {
            ones += nums[b % sz] - nums[a];
            maxOnes = max(maxOnes, ones);
        }

        return windowSize - maxOnes;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}