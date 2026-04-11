// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> row;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] <= k) { row.insert(nums[i]); }
            if (row.size() == k) { return nums.size() - i; }
        }

        return nums.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}