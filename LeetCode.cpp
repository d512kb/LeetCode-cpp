// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        int zeroes = 0;
        int ones = 0;

        for (char c : s) {
            if (c == '0') {
                if (ones) {
                    zeroes = 0;
                    ones = 0;
                }

                ++zeroes;
            }
            else {
                ++ones;

                if (ones <= zeroes) {
                    ans = max(ans, ones * 2);
                }
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