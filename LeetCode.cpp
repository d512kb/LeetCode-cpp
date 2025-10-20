// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;

        while (n > 1) {
            ans += n / 2;

            if (n & 1) {
                n = n / 2 + 1;
            }
            else {
                n /= 2;
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