// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sumPlus = 0;
        int sumMinus = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
            sumPlus = max(sumPlus, 0) + num;
            sumMinus = min(sumMinus, 0) + num;

            maxSum = max(maxSum, sumPlus);
            minSum = min(minSum, sumMinus);
        }

        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
