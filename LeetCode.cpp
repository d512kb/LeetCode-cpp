// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sIndex = s.size() - 1;
        int tIndex = t.size() - 1;
        int sSkip = 0;
        int tSkip = 0;

        while (true) {
            while (sIndex >= 0 && (s[sIndex] == '#' || sSkip > 0)) {
                sSkip += s[sIndex] == '#' ? 1 : -1;
                --sIndex;
            }

            while (tIndex >= 0 && (t[tIndex] == '#' || tSkip > 0)) {
                tSkip += t[tIndex] == '#' ? 1 : -1;
                --tIndex;
            }

            if (sIndex < 0 && tIndex < 0) { return true; }
            if (sIndex < 0 || tIndex < 0 || s[sIndex] != t[tIndex]) { return false; }
            --sIndex;
            --tIndex;
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