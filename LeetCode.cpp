// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> lengths(101);

        for (const auto& r : rectangles) { lengths[r[1]].push_back(r[0]); }
        for (auto& len : lengths) { sort(len.begin(), len.end()); }

        vector<int> result;

        for (const auto& p : points) {
            int rectNumber = 0;
            for (int h = p[1]; h <= 100; ++h) {
                const auto& len = lengths[h];
                rectNumber += distance(lower_bound(len.begin(), len.end(), p[0]), len.end());
            }

            result.push_back(rectNumber);
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}