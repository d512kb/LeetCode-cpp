// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x - z);
        int b = abs(y - z);

        if (a < b) { return 1; }
        if (a > b) { return 2; }
        return 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}