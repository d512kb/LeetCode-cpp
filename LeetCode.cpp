// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int sz = s.size();

        if (sz % 2) { return false; }

        int freePars = 0;
        int lockedPars = 0;

        for (int i = 0; i < sz; ++i) {
            if (locked[i] == '0') {
                ++freePars;
            } else {
                if (s[i] == ')') {
                    if (lockedPars > 0) {
                        --lockedPars;
                    } else if (freePars > 0) {
                        --freePars;
                    } else {
                        return false;
                    }
                } else {
                    ++lockedPars;
                }
            }
        }

        if (lockedPars == 0) { return true; }

        freePars = 0;
        lockedPars = 0;

        for (int i = sz - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                ++freePars;
            } else {
                if (s[i] == '(') {
                    if (lockedPars > 0) {
                        --lockedPars;
                    } else if (freePars > 0) {
                        --freePars;
                    } else {
                        return false;
                    }
                } else {
                    ++lockedPars;
                }
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}