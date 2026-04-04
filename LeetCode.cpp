// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;

        for (int i = 0; i < s.size();) {
            if (s[i] == 'X') {
                ans += 1;
                i += 3;
            }
            else {
                ++i;
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