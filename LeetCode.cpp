// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    double area = 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) +
                                            points[j][0] * (points[k][1] - points[i][1]) +
                                            points[k][0] * (points[i][1] - points[j][1]));

                    ans = max(ans, area);
                }
            }
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