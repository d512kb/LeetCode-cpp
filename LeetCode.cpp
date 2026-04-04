// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;

        for (int i = 1; i < timeSeries.size(); ++i) {
            ans += min(timeSeries[i] - timeSeries[i - 1], duration);
        }

        return ans + duration;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}