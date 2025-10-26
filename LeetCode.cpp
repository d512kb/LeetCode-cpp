// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int digitsSum = 0;
        int n = x;

        while (n) {
            digitsSum += n % 10;
            n /= 10;
        }

        if (x % digitsSum == 0) {
            return digitsSum;
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}