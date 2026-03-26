// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        array<int, 10> digits{};

        int m = 2 * n;
        while (m) { ++digits[m % 10]; m /= 10; }
        m = 3 * n;
        while (m) { ++digits[m % 10]; m /= 10; }
        while (n) { ++digits[n % 10]; n /= 10; }

        for (int i = 1; i < 10; ++i) {
            if (digits[i] != 1) { return false; }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}