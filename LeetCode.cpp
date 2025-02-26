// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int minutes = targetSeconds / 60;
        int seconds = targetSeconds % 60;

        if (minutes == 100) {
            --minutes;
            seconds += 60;
        }

        int result = calcCost(startAt, moveCost, pushCost, minutes, seconds);
        if (seconds + 60 <= 99 && minutes > 0) {
            result = min(result, calcCost(startAt, moveCost, pushCost, --minutes, seconds + 60));
        }

        return result;
    }
private:
    int calcCost(int startAt, int moveCost, int pushCost, int minutes, int seconds) {
        vector<int> digits;

        while (seconds) {
            digits.push_back(seconds % 10);
            seconds /= 10;
        }

        while (minutes > 0 && digits.size() < 2) { digits.push_back(0); } // seconds are always 2 digits if we have minutes too

        while (minutes) {
            digits.push_back(minutes % 10);
            minutes /= 10;
        }

        reverse(digits.begin(), digits.end());
        int result = 0;

        for (int n : digits) {
            if (startAt != n) {
                startAt = n;
                result += moveCost;
            }

            result += pushCost;
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