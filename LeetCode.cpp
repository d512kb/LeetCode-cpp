// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, size_t> numsCount;

        for (int n : nums) {
            ++numsCount[n];
        }

        int ans = 0;

        for (auto [_, count] : numsCount) {
            if (count > 1) {
                ans += (count - 1) * count / 2;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}