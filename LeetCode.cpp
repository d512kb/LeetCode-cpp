// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        constexpr int modulo = 1e9 + 7;
        const int sz = nums.size();
        int ans = 0;

        for (int i = 1; i < sz; ++i) { nums[i] += nums[i - 1]; }

        int from = 1, to = 1;
        for (int i = 0; i < sz - 2; ++i) {
            from = max(from, i + 1);
            while (from < sz - 1 && nums[from] - nums[i] < nums[i]) { ++from; }
            to = max(to, from);
            while (to < sz - 1 && nums[to] - nums[i] <= nums.back() - nums[to]) { ++to; }

            ans = (ans + to - from) % modulo;
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