// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int deduct = 10;

        while (n >= deduct) {
            n -= deduct;
            --deduct;

            ans = !ans;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}