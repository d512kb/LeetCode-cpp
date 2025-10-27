// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxElem = *max_element(nums.begin(), nums.end());

        return (maxElem + maxElem + k - 1) * k / 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}