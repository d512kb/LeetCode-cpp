// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int sz = s.size();
        int tz = t.size();
        vector<int64_t> dp(tz + 1);

        for (int i = 1; i <= sz; ++i) {
            dp[0] = 1;
            int prev = 1;
            int curr = 1;

            for (int j = 1; j <= tz; ++j) {
                curr = dp[j];

                if (s[i - 1] == t[j - 1]) {
                    dp[j] += prev;
                }

                prev = curr;
            }
        }

        return dp[tz];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}