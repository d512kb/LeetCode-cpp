// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        for (int i = 1; i < points.size(); ++i) {
            int xDiff = abs(points[i][0] - points[i - 1][0]);
            int yDiff = abs(points[i][1] - points[i - 1][1]);

            ans += max(xDiff, yDiff);
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