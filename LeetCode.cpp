// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            x = 1 / x;

        double result = 1;
        n = abs(n);

        while (n) {
            if (n % 2) {
                result *= x;
            }

            x *= x;
            n /= 2;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
