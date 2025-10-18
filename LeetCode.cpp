// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;
        int sign = 1;

        for (int n : nums) {
            ans += sign * n;
            sign = -sign;
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