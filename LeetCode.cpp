// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            if (i % m) {
                ans += i;
            }
            else {
                ans -= i;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}