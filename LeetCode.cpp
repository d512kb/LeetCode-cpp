// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        bool charsUsed[26]{};
        int ans = 1;

        for (char c : s) {
            if (charsUsed[c - 'a']) {
                memset(charsUsed, 0, sizeof(charsUsed));
                ++ans;
            }
            charsUsed[c - 'a'] = 1;
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