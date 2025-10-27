// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = (n * 2) * n / 2;
        int evenSum = (2 + n * 2) * n / 2;

        return gcd(oddSum, evenSum);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}