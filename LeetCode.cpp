// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i]) { return 1; }
        }

        return 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}