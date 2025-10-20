// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, size_t> mp;

        for (int n : nums) {
            ++mp[n];
        }

        int ans = 0;

        for (auto [num, count] : mp) {
            auto iterA = mp.find(num - k);
            auto iterB = mp.find(num + k);

            if (iterA != mp.end()) {
                ans += count * iterA->second;
            }
            if (iterB != mp.end()) {
                ans += count * iterB->second;
            }
        }

        return ans / 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}