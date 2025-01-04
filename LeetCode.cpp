// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto getDigits = [](int n) {
            vector<char> digits(10);

            while (n > 0) {
                ++digits[n % 10];
                n /= 10;
            }

            return digits;
        };

        auto nDigits = getDigits(n);

        for (int i = 0; i < 32; ++i) {
            if (nDigits == getDigits(1 << i)) { return true; }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}