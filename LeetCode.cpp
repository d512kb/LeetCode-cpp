// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        map<int, int> pushTimes;
        int prevTime = 0;

        for (const auto& push : events) {
            pushTimes[push[0]] = max(pushTimes[push[0]], push[1] - prevTime);
            prevTime = push[1];
        }

        vector<int> longestPush(2);

        for (const auto& [id, pushTime] : pushTimes) {
            if (pushTime > longestPush[1]) {
                longestPush[0] = id;
                longestPush[1] = pushTime;
            }
            else if (pushTime == longestPush[1] && id < longestPush[0]) {
                longestPush[0] = id;
                longestPush[1] = pushTime;
            }
        }

        return longestPush[0];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}