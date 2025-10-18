// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xPoints;
        xPoints.reserve(points.size());

        for (const auto& p : points) {
            xPoints.push_back(p[0]);
        }

        sort(xPoints.begin(), xPoints.end());
        int ans = 0;

        for (int i = 1; i < xPoints.size(); ++i) {
            ans = max(ans, xPoints[i] - xPoints[i - 1]);
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