// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        constexpr int modulo = 1e9 + 7;
        const int sz = strength.size();

        vector<pair<int, int>> minRanges(sz, { 0, sz - 1 }); // [left, right]
        vector<pair<int, int>> monoStack; // index, value
        monoStack.reserve(sz);

        for (int i = 0; i < sz; ++i) {
            while (!monoStack.empty() && strength[i] <= monoStack.back().second) {
                minRanges[monoStack.back().first].second = i - 1;
                monoStack.pop_back();
            }

            monoStack.emplace_back(i, strength[i]);
        }

        monoStack.clear();

        for (int i = sz - 1; i >= 0; --i) {
            while (!monoStack.empty() && strength[i] < monoStack.back().second) {
                minRanges[monoStack.back().first].first = i + 1;
                monoStack.pop_back();
            }

            monoStack.emplace_back(i, strength[i]);
        }

        const int shiftSize = 2;
        vector<int64_t> prefixSum(sz + shiftSize);
        vector<int64_t> prefixSumSum(sz + shiftSize);
        partial_sum(strength.begin(), strength.end(), prefixSum.begin() + shiftSize, [modulo](int a, int b) { return (a + b) % modulo; });
        partial_sum(prefixSum.begin(), prefixSum.end(), prefixSumSum.begin(), [modulo](int a, int b) { return (a + b) % modulo; });

        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            const int leftIndexSum = minRanges[i].first + shiftSize;
            const int rightIndexSum = minRanges[i].second + shiftSize;
            const int leftSideSize = i - minRanges[i].first + 1;
            const int rightSideSize = minRanges[i].second - i + 1;

            int64_t rangeStrength = (prefixSumSum[rightIndexSum] - prefixSumSum[i + 1] + modulo) * leftSideSize % modulo;
            rangeStrength -= (prefixSumSum[i + 1] - prefixSumSum[leftIndexSum - 2] + modulo) * rightSideSize % modulo;
            rangeStrength = (rangeStrength + modulo) % modulo;

            ans = (rangeStrength * strength[i] + ans) % modulo;
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