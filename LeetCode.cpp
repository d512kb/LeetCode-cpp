// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        const auto& p1 = points[0];
        const auto& p2 = points[1];
        const auto& p3 = points[2];

        if (p1 == p2 || p1 == p3 || p2 == p3) { return false; }

        // division transformed into multiplication
        return (p1[1] - p2[1]) * (p2[0] - p3[0]) != (p2[1] - p3[1]) * (p1[0] - p2[0]);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}