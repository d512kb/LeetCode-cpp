// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> prefixSums(nums.size() + 1);

        for (int i = 1; i < prefixSums.size(); ++i) { prefixSums[i] = nums[i - 1] + prefixSums[i - 1]; }

        auto calcMax = [&](int len1, int len2) {
            int maxSum = 0;

            for (int i = len1; i < prefixSums.size() - len2; ++i) {
                int sum1 = prefixSums[i] - prefixSums[i - len1];

                for (int j = i + len2; j < prefixSums.size(); ++j) {
                    maxSum = max(maxSum, sum1 + prefixSums[j] - prefixSums[j - len2]);
                }
            }

            return maxSum;
        };

        return max(calcMax(firstLen, secondLen), calcMax(secondLen, firstLen));
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}