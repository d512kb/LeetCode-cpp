// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const int sz = values.size();
        int currMax = values.front();
        int ans = 0;

        for (int i = 1; i < sz; ++i) {
            currMax = max(currMax, values[i - 1]) - 1;
            ans = max(ans, currMax + values[i]);
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