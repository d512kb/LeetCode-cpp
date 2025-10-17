// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> result(nums.size());
        auto iter = result.rbegin();

        for (int n : nums) {
            if (n % 2) {
                *iter++ = 1;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}