// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int start = 0, end = s.size() - 1; start < end; ++start, --end) {
            s[start] = s[end] = min(s[start], s[end]);
        }

        return s;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}