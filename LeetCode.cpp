// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefixSum(arr.size() + 1);
        partial_sum(arr.begin(), arr.end(), prefixSum.begin() + 1);

        int ans = 0;

        for (int len = 1; len <= arr.size(); len += 2) {
            for (int i = 0, j = i + len; j <= arr.size(); ++i, ++j) {
                ans += prefixSum[j] - prefixSum[i];
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