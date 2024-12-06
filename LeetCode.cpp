// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        return checkNum(nums, 0, totalSum - target);
    }
private:
    int checkNum(vector<int>& nums, int index, int target) {
        if (target < 0) { return 0; }
        if (index == nums.size()) { return target == 0; }

        return checkNum(nums, index + 1, target) +
            checkNum(nums, index + 1, target - (2 * nums[index]));
    }
};  

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}