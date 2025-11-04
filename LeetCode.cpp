// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        for (int i = 2; i < coordinates.size(); ++i) {
            if (!shareOneLine(coordinates[0], coordinates[1], coordinates[i])) {
                return false;
            }
        }

        return true;
    }
private:
    inline bool shareOneLine(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        return (p2[1] - p1[1]) * (p3[0] - p2[0]) == (p3[1] - p2[1]) * (p2[0] - p1[0]);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}