// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        const int sz = nums.size();
        if (sz <= 2) { return true; }

        for (int i = 1; i < sz; ++i) {
            if (nums[i - 1] + nums[i] >= m) { return true; }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}