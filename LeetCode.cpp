// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{ p1, p2, p3, p4 };
        unordered_set<double> distances;

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int dist = calcDistance(points[i], points[j]);
                if (dist == 0) { return false; }
                distances.insert(dist);
            }
        }

        return distances.size() == 2;
    }

private:
    int calcDistance(const vector<int>& p1, const vector<int>& p2) {
        return pow(abs(p1[0] - p2[0]), 2) + pow(abs(p1[1] - p2[1]), 2);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}