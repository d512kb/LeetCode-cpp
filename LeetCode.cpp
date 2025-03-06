// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        const int modulo = 1e9 + 7;
        int ans = 1;
        int currentStreak = 1;

        for (int i = 1, sz = s.size(); i < sz; ++i) {
            if (s[i] != s[i - 1]) { currentStreak = 0; }
            ans = (ans + ++currentStreak) % modulo;
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