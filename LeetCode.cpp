// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (low; low <= high; ++low) {
            int digits = countDigits(low);
            if (digits % 2) {
                int newStep = 0;

                while (digits) {
                    newStep = newStep * 10 + 9;
                    --digits;
                }
                low = newStep;

                continue;
            }

            int n = low;
            int leftSum = 0;
            int rightSum = 0;

            digits /= 2;

            for (int i = 0; i < digits; ++i) {
                rightSum += n % 10;
                n /= 10;
            }

            for (int i = 0; i < digits; ++i) {
                leftSum += n % 10;
                n /= 10;
            }

            if (leftSum == rightSum) {
                ++ans;
            }
        }

        return ans;
    }
private:
    char countDigits(int n) {
        int ans = 0;

        while (n > 0) {
            ++ans;
            n /= 10;
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