// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        int sz = s.size();
        vector<int> dp(sz + 1, 1);

        for (int i = 1; i < sz; ++i) {
            char num = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (num == 0 || (num > 26 && num % 10 == 0)) {
                return 0;
            }

            if (num < 10 || num > 26) {
                dp[i + 1] = dp[i];
            } else if (num == 10 || num == 20) {
                dp[i + 1] = dp[i - 1];
            } else {
                dp[i + 1] = dp[i] + dp[i - 1];
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