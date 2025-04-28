// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> primes(101, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i <= 100; ++i) {
            if (!primes[i]) { continue; }

            for (int val = i + i; val <= 100; val += i) {
                primes[val] = false;
            }
        }

        auto iterA = find_if(nums.begin(), nums.end(), [&primes](int val) { return primes[val]; });
        auto iterB = find_if(nums.rbegin(), nums.rend(), [&primes](int val) { return primes[val]; });

        return distance(iterA, iterB.base()) - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}