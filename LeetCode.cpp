// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int upperCut = 1000000007;
        vector<int> dp(high + 1);
        dp[0] = 1;
        uint64_t result = 0;

        for (int i = 1; i < low; ++i) {
            int tr = (i >= zero) ? dp[i - zero] : 0;
            tr += (i >= one) ? dp[i - one] : 0;
            dp[i] = tr % upperCut;
        }

        for (int i = low; i <= high; ++i) {
            int val = (dp[i - zero] + dp[i - one]) % upperCut;
            dp[i] = val;
            result += val;
        }

        return result % upperCut;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}