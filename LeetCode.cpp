// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }

        return static_cast<double>(maxSum) / k;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}