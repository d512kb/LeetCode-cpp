// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    // first increase i times, then duplicate d times
    // (i+1) * (d+1) >= k, and it's the best when the increase and duplication numbers are equal => i+1 == sqrt(k)
    int minOperations(int k) {
        int i = ceil(sqrt(k));
        int d = ceil(static_cast<double>(k) / i);

        return i - 1 + d - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}