// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ops = 0;

        while (target > startValue) {
            if (target % 2) {
                ++target;
                ++ops;
            }

            target /= 2;
            ++ops;
        }

        return ops + startValue - target;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}