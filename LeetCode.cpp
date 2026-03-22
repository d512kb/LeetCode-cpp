// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) { return false; }

        int sumDivisors = 1;

        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sumDivisors += i;

                int anotherDivisor = num / i;

                if (anotherDivisor != i) {
                    sumDivisors += anotherDivisor;
                }
            }
        }

        return sumDivisors == num;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}