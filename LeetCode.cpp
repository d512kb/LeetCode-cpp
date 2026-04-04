// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        unordered_set<int> averages;

        for (int left = 0, right = nums.size() - 1; left < right; ++left, --right) {
            if (averages.insert(nums[left] + nums[right]).second) {
                ++ans;
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