// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int64_t result = 1;
        int64_t resultNeg = 1;
        int maxNeg = numeric_limits<int>::min();
        int zeroCount = 0;

        for (int n : nums) {
            if (n > 0) {
                result *= n;
            } else if (n < 0) {
                resultNeg *= n;
                maxNeg = max(maxNeg, n);
            } else {
                ++zeroCount;
            }
        }

        if (zeroCount == nums.size()) { return 0; }
        if (nums.size() - zeroCount == 1) {
            if (zeroCount > 0) { return max<int64_t>(0, result * resultNeg); }
            return result * resultNeg;
        }

        if (resultNeg < 0) { resultNeg /= maxNeg; }
        return result * resultNeg;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}