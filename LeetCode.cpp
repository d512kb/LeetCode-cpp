// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1)
            return 1;

        unordered_map<double, int> slopes;
        int vertSlope = 0;
        int result = 0;

        for (int i = 0, sz = points.size(); i < sz; ++i) {
            slopes.clear();
            vertSlope = 0;

            for (int j = i + 1; j < sz; ++j) {
                double yDiff = points[j][1] - points[i][1];
                int xDiff = points[j][0] - points[i][0];

                if (xDiff) {
                    result = max(result, ++slopes[yDiff / xDiff] + 1);
                } else {
                    result = max(result, ++vertSlope + 1);
                }
            }
        }

        return result;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}