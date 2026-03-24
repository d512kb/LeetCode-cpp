// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 0x55555555;

        return n > 0 && (n & n - 1) == 0 && (n & mask);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}