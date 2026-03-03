// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> duplicates;
        int dup = 0;

        for (int n : nums) {
            if (!duplicates.insert(n).second) {
                dup = n;
                break;
            }
        }

        int origSum = nums.size() * (nums.size() + 1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> result{ dup, 0 };
        result[1] = dup + (origSum - sum);

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}