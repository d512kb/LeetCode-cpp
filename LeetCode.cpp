// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = 0;
        int maxSum = nums[0];

        for (int num : nums) {
            currMax = max(currMax, 0) + num;
            maxSum = max(maxSum, currMax);
        }

        return maxSum;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
