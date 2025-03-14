// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        const int maxSz = 1 + *max_element(nums.begin(), nums.end());
        vector<int> counts(maxSz);

        for (int n : nums) { ++counts[n]; }
        for (int i = 0, pos = 0; i < maxSz; ++i) {
            while (counts[i] > 0) {
                nums[pos++] = i;
                --counts[i];
            }
        }

        int min = nums.front();
        int ans = 0;

        for (int n : nums) {
            if (n - min > k) {
                min = n;
                ++ans;
            }
        }

        return 1 + ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}