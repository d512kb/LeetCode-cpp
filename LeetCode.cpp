// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0;
        int maxOnes = 0;
        int zeros = 0;
        int maxZeros = 0;

        for (char c : s) {
            if (c == '0') {
                maxOnes = max(maxOnes, exchange(ones, 0));
                ++zeros;
            }
            else {
                maxZeros = max(maxZeros, exchange(zeros, 0));
                ++ones;
            }
        }

        maxOnes = max(maxOnes, ones);
        maxZeros = max(maxZeros, zeros);

        return maxOnes > maxZeros;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}