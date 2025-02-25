// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto firstNum = upper_bound(nums.begin(), nums.end(), nums.front());
        auto lastNum = upper_bound(nums.rbegin(), nums.rend(), nums.back(), greater<>{}).base();

        int result = nums.size();
        result -= distance(nums.begin(), firstNum);
        result -= distance(lastNum, nums.end());

        return max(result, 0);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}