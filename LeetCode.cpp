// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int leftSum = 0;
        int rightSum = n * (n + 1) / 2;

        for (int i = 1; i <= n; ++i) {
            leftSum += i;

            if (leftSum == rightSum) {
                return i;
            }

            rightSum -= i;
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