// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return count_if(nums.begin(), nums.end(), [k](int n) { return n < k; });
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}