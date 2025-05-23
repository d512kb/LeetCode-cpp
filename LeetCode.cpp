// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        const auto sz = nums.size();
        vector<size_t> numbersCount(sz + 1);
        size_t left = 0;
        size_t mid = 0;
        size_t right = 0;
        size_t uniqueNumbers = 0;
        int ans = 0;

        for (right; right < sz; ++right) {
            if (++numbersCount[nums[right]] == 1 && ++uniqueNumbers > k) {
                --numbersCount[nums[mid++]];
                left = mid;
                uniqueNumbers = k;
            }

            if (uniqueNumbers == k) {
                while (numbersCount[nums[mid]] > 1) {
                    --numbersCount[nums[mid++]];
                }

                ans += mid - left + 1;
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