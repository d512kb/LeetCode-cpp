// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        vector<int> dp(sz);
        vector<int> dpPrev(sz);

        for (int start = sz - 1; start >= 0; --start) {
            swap(dp, dpPrev);
            dpPrev[start] = 0; // for 'xx' case, so we don't append extra item for empty dpPrev
            dp[start] = 1;

            for (int fin = start + 1; fin < sz; ++fin) {
                if (s[start] != s[fin]) {
                    dp[fin] = max(dp[fin - 1], dpPrev[fin]);
                } else {
                    dp[fin] = 2 + dpPrev[fin - 1]; // 'xx' case
                }
            }
        }

        return dp.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}