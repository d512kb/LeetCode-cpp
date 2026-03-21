// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;

            for (int c = 1, j = i; j < nums.size(); ++j, ++c) {
                sum += nums[j];

                if (c > r) { break; }
                if (c >= l && sum > 0) { ans = min(ans, sum); }
            }
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}