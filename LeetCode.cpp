// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        constexpr int endVal = 51;
        vector<int> count(endVal);
        int ans = -1;

        for (int num : nums) {
            ++count[num];
        }

        if (k == 1) {
            for (int i = 0; i < endVal; ++i) {
                if (count[i] == 1 && i > ans) {
                    ans = i;
                }
            }

            return ans;
        } else if (k < nums.size()) {
            if (count[nums.front()] == 1) { ans = nums.front(); }
            if (count[nums.back()] == 1 && nums.back() > ans) {
                ans = nums.back();
            }
        } else {
            return *max_element(nums.begin(), nums.end());
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