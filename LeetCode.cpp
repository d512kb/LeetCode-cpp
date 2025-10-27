// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int iterations = 0;
        int stringLen = 1;

        while (stringLen < k) {
            stringLen *= 2;
        }

        while (k > 1) {
            stringLen /= 2;

            if (k > stringLen) {
                ++iterations;
                k -= stringLen;
            }
        }

        return iterations % 26 + 'a';
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}