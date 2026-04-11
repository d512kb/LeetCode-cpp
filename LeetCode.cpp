// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        array<int, 101> counts{};

        for (int n : nums) {
            ++counts[n];
        }

        auto prime = [](int n) {
            if (n <= 1) { return false; }
            if (n <= 3) { return true; }

            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) { return false; }
            }

            return true;
            };

        return any_of(counts.begin(), counts.end(), prime);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}