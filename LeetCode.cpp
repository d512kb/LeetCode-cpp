// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) { return a[1] < b[1]; });

        int r = points[0][1];
        int n = 1;

        for (auto& p : points) {
            if (p[0] > r) {
                r = p[1];
                ++n;
            }
        }

        return n;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
