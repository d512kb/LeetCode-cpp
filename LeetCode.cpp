// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        const int qsz = queries.size();

        for (int numIndex = 0; numIndex < nums.size(); ++numIndex) {
            if (nums[numIndex] == 0) { continue; }

            int n = nums[numIndex];
            vector<char> dp(n + 1);
            dp[0] = 1;

            for (int i = 0; i < qsz; ++i) {
                if (queries[i][0] > numIndex || queries[i][1] < numIndex) { continue; }
                int qVal = queries[i][2];

                for (int sum = n - qVal; sum >= 0; --sum) {
                    dp[sum + qVal] |= dp[sum];
                }

                if (dp[n] == 1) {
                    ans = max(ans, i + 1);
                    break;
                }
            }

            if (dp[n] == 0) { return -1; }
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