// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if (low == high) { return low % 2; }

        int ans = 0;

        if (low % 2) { ++ans; ++low; }
        if (high % 2) { ++ans; --high; }

        return ans + (high - low) / 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}