// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sz1 = s1.size();
        int sz2 = s2.size();
        vector<int> dp(sz2 + 1);
        vector<int> dpPrev(sz2 + 1);

        for (int i = 1; i <= sz2; ++i) {
            dp[i] = dp[i - 1] + s2[i - 1];
        }

        for (int i = 1; i <= sz1; ++i) {
            swap(dp, dpPrev);
            dp[0] = dpPrev[0] + s1[i - 1];

            for (int j = 1; j <= sz2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = dpPrev[j - 1];
                } else {
                    dp[j] = min(s2[j - 1] + dp[j - 1], s1[i - 1] + dpPrev[j]);
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