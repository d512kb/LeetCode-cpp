// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int opIndex = log2(k);
        long long frameLength = pow(2, opIndex + 1);
        int changeCounter = 0;

        while (k > 1) {
            frameLength /= 2;

            if (k > frameLength) {
                if (operations[opIndex]) {
                    ++changeCounter;
                }
                k -= frameLength;
            }

            --opIndex;
        }

        return changeCounter % 26 + 'a';
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}