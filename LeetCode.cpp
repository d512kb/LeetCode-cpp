// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && nums[i] < 0 && k > 0; ++i, --k) {
            nums[i] = -nums[i];
        }

        int ans = accumulate(nums.begin(), nums.end(), 0);

        if (k > 0) {
            if (k % 2 == 0) {
                return ans;
            }
            else {
                return ans - 2 * *min_element(nums.begin(), nums.end());
            }
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