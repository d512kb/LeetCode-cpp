// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int b = 0;
        int ans = 0;

        for (char c : s) {
            if (c == 'R') {
                ++b;
            }
            else {
                --b;
            }

            if (b == 0) {
                ++ans;
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