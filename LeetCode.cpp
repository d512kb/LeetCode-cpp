// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isThree(int n) {
        if (n <= 3) { return false; }

        int divCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) { if (++divCount > 3) { return false; } }
        }

        return divCount == 3;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}