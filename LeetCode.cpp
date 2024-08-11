// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int sz = s.size();
        vector<int> dp(sz);
        vector<int> dpPrev(sz);

        for (int start = sz - 1; start >= 0; --start) {
            swap(dp, dpPrev);
            dpPrev[start] = 0;
            dp[start] = 1;

            for (int fin = start + 1; fin < sz; ++fin) {
                if (s[start] == s[fin]) {
                    dp[fin] = 2 + dpPrev[fin - 1];
                } else {
                    dp[fin] = max(dp[fin - 1], dpPrev[fin]);
                }
            }
        }

        return sz - dp.back();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}