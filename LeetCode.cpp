// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == -1) {
            if (dividend == numeric_limits<int>::min())
                return numeric_limits<int>::max();
            else
                return -dividend;
        } else if (divisor == 1) {
            return dividend;
        }

        bool resultIsNegative = false;

        if (dividend > 0) {
            dividend = -dividend;
            resultIsNegative = !resultIsNegative;
        }

        if (divisor > 0) {
            divisor = -divisor;
            resultIsNegative = !resultIsNegative;
        }

        int result = dividend <= divisor;
        int stepSize = divisor;

        while (dividend - divisor <= stepSize) {
            divisor += stepSize;
            ++result;
        }

        return resultIsNegative ? -result : result;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << sol.divide(numeric_limits<int>::max(), 2) << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
