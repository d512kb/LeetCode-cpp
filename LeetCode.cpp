// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& boxInfo1, const auto& boxInfo2) { return boxInfo1[1] > boxInfo2[1]; });

        int ans = 0;

        for (const auto& boxInfo : boxTypes) {
            int load = min(boxInfo[0], truckSize);

            truckSize -= load;
            ans += load * boxInfo[1];

            if (truckSize == 0) { break; }
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