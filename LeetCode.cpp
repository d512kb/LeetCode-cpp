// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if ((leftSum - rightSum) % 2 == 0) {
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