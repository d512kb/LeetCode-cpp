// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        const int sz = nums.size();
        int corr = 0;

        for (int i = 0; i < sz; ++i) {
            if ((nums[i] -= corr) < 0) { return false; }
            corr += nums[i];
            if (i - k + 1 >= 0) { corr -= nums[i - k + 1]; }
        }

        return corr == 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}