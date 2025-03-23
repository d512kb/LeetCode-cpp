// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int minDiff = numeric_limits<int>::max();
        for (int i = 1; i < nums.size(); ++i) {
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        }

        return minDiff;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}