// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0, sz = nums.size(), sum = 0; i < sz; ++i) {
            rightSum -= nums[i];
            if (sum == rightSum) {
                return i;
            }
            sum += nums[i];
        }

        return -1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}