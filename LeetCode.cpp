// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums.front();

        for (int n : nums) {
            if (abs(n) < abs(ans)) {
                ans = n;
            } else if (abs(n) == abs(ans) && n > ans) {
                ans = n;
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