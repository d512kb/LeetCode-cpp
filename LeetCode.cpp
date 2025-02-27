// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<array<int, 2>> sortedPoints;

        for (const auto& p : points) { sortedPoints.push_back({ p[0], p[1] }); }
        sort(sortedPoints.begin(), sortedPoints.end());

        vector<int> result;

        for (const auto& query : queries) {
            auto from = lower_bound(sortedPoints.begin(), sortedPoints.end(), array<int, 2>{query[0] - query[2], 0});
            int number = 0;

            for (from; from != sortedPoints.end() && (*from)[0] <= query[0] + query[2]; ++from) {
                if (calcDistance(query, *from) <= query[2]) {
                    ++number;
                }
            }

            result.push_back(number);
        }

        return result;
    }
private:
    inline double calcDistance(const auto& p1, const auto& p2) const {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}