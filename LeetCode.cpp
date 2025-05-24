// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        const auto sz = s.size();
        set<int64_t, greater<>> primes;

        for (int i = 0; i < sz; ++i) {
            int64_t val = 0;

            for (int j = i; j < sz; ++j) {
                val *= 10;
                val += s[j] - '0';

                if (isPrime(val))
                    primes.insert(val);
            }
        }

        if (primes.size() < 3) {
            return accumulate(primes.begin(), primes.end(), 0ll);
        }

        return accumulate(primes.begin(), next(primes.begin(), 3), 0ll);
    }
private:
    bool isPrime(int64_t val) {
        if (val == 1) { return false; }

        for (int64_t i = 2; i * i <= val; ++i) {
            if (val % i == 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}