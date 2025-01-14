// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));

        auto calcOperations = [&](auto&& self, int left, int right, int score) -> int {
            if (left >= right) { return 0; }

            int& ans = memo[left][right];
            if (ans != -1) { return ans; }

            ans = 0;
            if (nums[left] + nums[left + 1] == score) { ans = max(ans, 1 + self(self, left + 2, right, score)); }
            if (nums[left] + nums[right] == score) { ans = max(ans, 1 + self(self, left + 1, right - 1, score)); }
            if (nums[right - 1] + nums[right] == score) { ans = max(ans, 1 + self(self, left, right - 2, score)); }

            return ans;
        };

        int ans = 0;

        ans = max(ans, 1 + calcOperations(calcOperations, 2, nums.size() - 1, nums[0] + nums[1]));
        ans = max(ans, 1 + calcOperations(calcOperations, 1, nums.size() - 2, nums.front() + nums.back()));
        ans = max(ans, 1 + calcOperations(calcOperations, 0, nums.size() - 3, nums.back() + nums[nums.size() - 2]));

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}