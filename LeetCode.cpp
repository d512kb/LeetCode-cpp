// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        const int sz = points.size();
        unordered_set<size_t> availablePoints;

        for (const auto& p : points) {
            availablePoints.insert(p[0] << 16 | p[1]);
        }

        int ans = numeric_limits<int>::max();

        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                const auto& p1 = points[i];
                const auto& p2 = points[j];

                if (p1[0] == p2[0] || p1[1] == p2[1]) { continue; }

                if (availablePoints.contains(p1[0] << 16 | p2[1]) && availablePoints.contains(p2[0] << 16 | p1[1])) {
                    ans = min(ans, abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]));
                }
            }
        }

        return ans == numeric_limits<int>::max() ? 0 : ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}