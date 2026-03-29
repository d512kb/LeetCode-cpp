// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int pos = 0;
        bool seen = false;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                if (seen) { return -1; }
                seen = true;
                pos = i;
            }
        }

        return nums.size() - pos - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}