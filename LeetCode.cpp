// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int maxVal = nums.size() - 1;
        unordered_map<int, size_t> counts;

        for (int n : nums) {
            if (n > maxVal) { return false; }
            else if (n == maxVal && ++counts[n] > 2) { return false; }
            else if (n < maxVal && ++counts[n] > 1) { return false; }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}