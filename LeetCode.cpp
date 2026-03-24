// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) { return 0; }

        vector<int> values(n + 1);
        values[0] = 0;
        values[1] = 1;
        int ans = 1;

        for (int i = 2; i <= n; ++i) {
            if (i % 2) {
                values[i] = values[i / 2] + values[i / 2 + 1];
            }
            else {
                values[i] = values[i / 2];
            }

            ans = max(ans, values[i]);
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