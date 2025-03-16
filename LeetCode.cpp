// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fifths = 0;
        int tens = 0;

        for (int b : bills) {
            if (b == 5) { ++fifths; } else if (b == 10) {
                if (fifths > 0) {
                    --fifths;
                    ++tens;
                } else {
                    return false;
                }
            } else {
                if (tens > 0 && fifths > 0) {
                    --tens;
                    --fifths;
                } else if (fifths >= 3) {
                    fifths -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}