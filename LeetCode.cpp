// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int64_t sidesSum = accumulate(nums.begin(), nums.end() - 1, 0l);
        for (int lastSide = nums.size() - 1; lastSide >= 2; --lastSide, sidesSum -= nums[lastSide]) {
            if (sidesSum > nums[lastSide]) { return sidesSum + nums[lastSide]; }
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}