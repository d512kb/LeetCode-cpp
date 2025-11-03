// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int len = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] != s[i]) {
                if (len == k) { return true; }
                len = 1;
            }
            else {
                ++len;
            }
        }

        return len == k;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}