// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutesAngle = minutes * 6;
        double hourAngle = hour * 30 + minutesAngle / 12;
        double angle = abs(hourAngle - minutesAngle);

        return angle > 180 ? 360 - angle : angle;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}