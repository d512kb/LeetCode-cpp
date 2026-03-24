// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) { return false; }

        while (n > 1 && n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}