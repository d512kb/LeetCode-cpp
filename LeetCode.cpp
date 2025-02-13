// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int sz = s.size();
        int minOpenPars = 0;
        int maxOpenPars = 0;

        for (int i = 0; i < sz; ++i) {
            if (locked[i] == '0') {
                --minOpenPars; // for the case when it's a closed parenthesis
                ++maxOpenPars; // for the case when it's an open parenthesis
            } else {
                if (s[i] == ')') {
                    --minOpenPars;
                    --maxOpenPars;
                } else {
                    ++minOpenPars;
                    ++maxOpenPars;
                }
            }

            if (minOpenPars < 0) { minOpenPars = 0; } // should've been one more open parentheses back then, let's correct it
            if (maxOpenPars < 0) { return false; } // there is no more spare open parentheses for one more closed parenthesis
        }

        return minOpenPars == 0 && maxOpenPars % 2 == 0; // all closed parentheses are matched and the rest can match together
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}