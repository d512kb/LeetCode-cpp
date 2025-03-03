// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        const int sz = books.size();
        vector<int> dp(sz + 1, numeric_limits<int>::max());
        dp.front() = 0;

        for (int i = 0; i < sz; ++i) {
            int availableWidth = shelfWidth;
            int maxHeight = 0;
            int& ans = dp[i + 1];

            for (int j = i; j >= 0; --j) {
                if (availableWidth < books[j][0]) { break; }
                availableWidth -= books[j][0];
                maxHeight = max(maxHeight, books[j][1]);
                ans = min(ans, maxHeight + dp[j]);
            }
        }

        return dp.back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}