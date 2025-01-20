// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        vector<int> links(nums.size(), -1);
        int maxChainIndex = 0;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] >= dp[i]) {
                    dp[i] = 1 + dp[j];
                    links[i] = j;
                    if (dp[i] > dp[maxChainIndex]) { maxChainIndex = i; }
                }
            }
        }

        vector<int> result;

        while (maxChainIndex >= 0) {
            result.push_back(nums[maxChainIndex]);
            maxChainIndex = links[maxChainIndex];
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}