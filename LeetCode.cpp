// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countTime(string time) {
        int ans = 1;

        if (time[0] == '?' && time[1] == '?') { ans *= 24; }
        else if (time[0] == '?') { ans *= 2 + (time[1] - '0' < 4); }
        else if (time[1] == '?') { if (time[0] == '2') ans *= 4; else ans *= 10; }
        if (time[3] == '?') { ans *= 6; }
        if (time[4] == '?') { ans *= 10; }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}