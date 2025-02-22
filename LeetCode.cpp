// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        array<int, 26> leftChars{};
        array<int, 26> rightChars{};

        for (char c : s) { ++rightChars[c - 'a']; }

        int rightCount = 26 - count(rightChars.begin(), rightChars.end(), 0);
        int leftCount = 0;
        int ans = 0;

        for (char c : s) {
            if (--rightChars[c - 'a'] == 0) { --rightCount; };
            if (++leftChars[c - 'a'] == 1) { ++leftCount; };

            if (leftCount == rightCount) { ++ans; }
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