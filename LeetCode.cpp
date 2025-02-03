// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int sz = arr.size();
        constexpr int modulo = 1e9 + 7;
        stack<int> monoStack;
        vector<int> dp(sz);
        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            while (!monoStack.empty() && arr[monoStack.top()] >= arr[i]) {
                monoStack.pop();
            }

            if (monoStack.empty()) {
                dp[i] = arr[i] * (i + 1) % modulo;
            } else {
                int j = monoStack.top();
                dp[i] = (dp[j] + (i - j) * arr[i]) % modulo;
            }

            monoStack.push(i);
            ans = (ans + dp[i]) % modulo;
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