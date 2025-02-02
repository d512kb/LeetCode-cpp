// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) { return 10; }

        constexpr int modulo = 1e9 + 7;
        array<int64_t, 10> dp{ 1,1,1,1,1,0,1,1,1,1 };
        array<int64_t, 10> dpPrev;

        for (--n; n > 0; --n) {
            swap(dp, dpPrev);

            dp[0] = (dpPrev[4] + dpPrev[6]) % modulo;
            dp[1] = (dpPrev[6] + dpPrev[8]) % modulo;
            dp[2] = (dpPrev[7] + dpPrev[9]) % modulo;
            dp[3] = (dpPrev[4] + dpPrev[8]) % modulo;
            dp[4] = (dpPrev[0] + dpPrev[3] + dpPrev[9]) % modulo;
            dp[6] = (dpPrev[0] + dpPrev[1] + dpPrev[7]) % modulo;
            dp[7] = (dpPrev[2] + dpPrev[6]) % modulo;
            dp[8] = (dpPrev[1] + dpPrev[3]) % modulo;
            dp[9] = (dpPrev[2] + dpPrev[4]) % modulo;
        }

        return accumulate(dp.begin(), dp.end(), 0l) % modulo;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}