// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();

        int dp1[2]{ 0, 0 };
        int dp2[2]{ 0, 0 };

        dp1[1] = nums[0];
        for (int i = 1; i < sz - 1; ++i) {
            dp1[0] = exchange(dp1[1], max(nums[i] + dp1[0], dp1[1]));
            dp2[0] = exchange(dp2[1], max(nums[i] + dp2[0], dp2[1]));
        }
        dp2[1] = max(nums.back() + dp2[0], dp2[1]);

        return max(dp1[1], dp2[1]);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}