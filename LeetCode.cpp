// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = neededTime[0];
        int maxTime = time;
        int ans = 0;

        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                time += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
            } else {
                ans += time - maxTime;
                time = neededTime[i];
                maxTime = time;
            }
        }

        return ans + time - maxTime;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}