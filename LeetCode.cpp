// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;

        while (mainTank >= 5) {
            int injections = mainTank / 5;
            mainTank -= injections * 5;
            ans += injections * 5 * 10;

            mainTank += min(injections, additionalTank);
            additionalTank -= min(injections, additionalTank);
        }

        ans += mainTank * 10;

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}