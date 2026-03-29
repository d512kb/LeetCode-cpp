// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) { return 0; }
        if (n % 2) { return n; }
        return n / 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}