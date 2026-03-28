// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;

        while (n) {
            if (n % 10) {
                x = x * 10 + n % 10;
            }

            n /= 10;
        }

        int sum = 0;
        long long xRev = 0;

        while (x) {
            sum += x % 10;
            xRev = xRev * 10 + x % 10;

            x /= 10;
        }

        return xRev * sum;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}