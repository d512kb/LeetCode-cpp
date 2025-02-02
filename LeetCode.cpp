// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visitedPoints{ {0, 0} };
        pair<int, int> point;

        for (char c : path) {
            if (c == 'N') { ++point.second; } else if (c == 'E') { ++point.first; } else if (c == 'S') { --point.second; } else { --point.first; }

            if (!visitedPoints.insert(point).second) { return true; }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}