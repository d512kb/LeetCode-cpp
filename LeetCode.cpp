// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int sz = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());

        queue<int> maxes;
        int right = 0;

        for (; right < sz; ++right) {
            if (nums[right] == maxElem) {
                maxes.push(right);
                if (maxes.size() == k) {
                    break;
                }
            }
        }

        if (maxes.size() < k) { return 0; }

        int64_t leftPart = 1 + maxes.front();
        int64_t result = leftPart;
        for (++right; right < sz; ++right) {
            if (nums[right] != maxElem) {
                result += leftPart;
            } else {
                maxes.pop();
                maxes.push(right);
                leftPart = 1 + maxes.front();
                result += leftPart;
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