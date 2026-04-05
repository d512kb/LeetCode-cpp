// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        size_t primeCount = 0;
        size_t compositeCount = 0;

        for (int i = 1; i <= n; ++i) {
            if (isPrime(i)) {
                ++primeCount;
            }
            else {
                ++compositeCount;
            }
        }

        return (fact(primeCount) * fact(compositeCount)) % 1000000007;
    }
private:
    bool isPrime(size_t n) {
        if (n <= 1) { return false; }
        if (n <= 3) { return true; }

        for (size_t i = 2; i * i <= n; ++i) {
            if (n % i == 0) { return false; }
        }

        return true;
    }

    size_t fact(size_t n) {
        size_t result = 1;

        for (int i = 2; i <= n; ++i) {
            result = (result * i) % 1000000007;
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}