// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int bestDivisor = divisors[0];
        int bestDivisorScore = 0;

        for (int d : divisors) {
            int currentScore = 0;

            for (int n : nums) {
                if (n % d == 0) {
                    ++currentScore;
                }
            }

            if (currentScore > bestDivisorScore) {
                bestDivisor = d;
                bestDivisorScore = currentScore;
            }
            else if (currentScore == bestDivisorScore && d < bestDivisor) {
                bestDivisor = d;
            }
        }

        return bestDivisor;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}