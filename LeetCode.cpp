// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landEarliest = landStartTime[0] + landDuration[0];
        int waterEarliest = waterStartTime[0] + waterDuration[0];
        int ans = numeric_limits<int>::max();

        for (int i = 0; i < landStartTime.size(); ++i) {
            landEarliest = min(landEarliest, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < waterStartTime.size(); ++i) {
            ans = min(ans, max(landEarliest, waterStartTime[i]) + waterDuration[i]);

            waterEarliest = min(waterEarliest, waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < landStartTime.size(); ++i) {
            ans = min(ans, max(waterEarliest, landStartTime[i]) + landDuration[i]);
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