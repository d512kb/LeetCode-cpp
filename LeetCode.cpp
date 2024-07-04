// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<uint64_t> dp(power.begin(), power.end());
        uint64_t mx = 0;

        for (int i = 1, j = 0, sz = power.size(); i < sz; ++i) {
            int& currVal = power[i];

            if (power[i - 1] == currVal) {
                dp[i] = currVal + dp[i - 1];
            } else {
                for (; power[j] + 2 < currVal; ++j) {
                    mx = max(mx, dp[j]);
                }
                dp[i] = currVal + mx;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}