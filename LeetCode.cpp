// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int diff = numeric_limits<int>::max();

        for (int i = 1; i < timePoints.size(); ++i) {
            diff = min(diff, getMinutes(timePoints[i]) - getMinutes(timePoints[i - 1]));
        }

        diff = min(diff, (getMinutes(timePoints.front()) + 24 * 60) - getMinutes(timePoints.back()));

        return diff;
    }
private:
    int getMinutes(const string& str) {
        int hours;
        int minutes;

        from_chars(&str[0], &str[2], hours);
        from_chars(&str[3], &str[5], minutes);

        return hours * 60 + minutes;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}