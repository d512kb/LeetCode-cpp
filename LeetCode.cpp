// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) { return 0; }
        if (n > k) {
            return static_cast<int64_t>(k) * (n - k);
        }
        return static_cast<int64_t>(k) * (m - k);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}