// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> points(1001);
        iota(points.begin(), points.end(), 0);
        vector<int> result;

        for (auto& edge : edges) {
            int p1 = edge[0];
            int p2 = edge[1];

            while (p1 != points[p1]) { p1 = points[p1]; }
            while (p2 != points[p2]) { p2 = points[p2]; }

            if (p1 == p2) { result = edge; } else { points[max(p1, p2)] = min(p1, p2); }
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