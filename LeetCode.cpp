// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}