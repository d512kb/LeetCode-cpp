// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> values(maxVal + 1);

        for (int n : nums) {
            ++values[max(0, n - k)];
            if (n + k + 1 <= maxVal) {
                --values[n + k + 1];
            }
        }

        int ans = 0;
        int currentSum = 0;

        for (int val : values) {
            currentSum += val;
            ans = max(ans, currentSum);
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