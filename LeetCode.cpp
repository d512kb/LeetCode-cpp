// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums.size() % (i + 1) == 0) {
                ans += nums[i] * nums[i];
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