// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size() + 1;
        int len2 = word2.size() + 1;

        vector<vector<uint16_t>> dp(len1, vector<uint16_t>(len2, 0));

        for (int i = 0; i < len1; ++i) {
            dp[i][0] = i;
        }

        for (int i = 0; i < len2; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i < len1; ++i) {
            for (int j = 1; j < len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        return dp.back().back();
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}