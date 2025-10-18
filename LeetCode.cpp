// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for (char c : columnTitle) {
            ans = ans * 26 + (c - 'A' + 1);
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