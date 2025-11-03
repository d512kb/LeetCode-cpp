// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixLen = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] + 1 == nums[i]) {
                ++prefixLen;
            }
            else {
                break;
            }
        }

        int prefixSum = (nums[0] + nums[prefixLen - 1]) * prefixLen / 2;
        int ans = prefixSum;
        auto iter = nums.begin() + prefixLen - 1;

        while (true) {
            if (find(iter, nums.end(), ans) == nums.end()) {
                return ans;
            }
            ++ans;
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