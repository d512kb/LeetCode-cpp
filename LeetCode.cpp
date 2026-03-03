// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[0] == nums[1] && nums[1] == nums[2]) { return "equilateral"; }

        for (int i = 0; i < 3; ++i) {
            if (nums[i] + nums[(i + 1) % 3] <= nums[(i + 2) % 3]) { return "none"; }
            if (nums[i] == nums[(i + 1) % 3]) { return "isosceles"; }
        }

        return "scalene";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}