// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool inPair = false;

        for (char c : s) {
            if (c == '|') {
                inPair = !inPair;
            }

            if (c == '*' && !inPair) {
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