// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (const auto& account : accounts) {
            ans = max(ans, accumulate(account.begin(), account.end(), 0));
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