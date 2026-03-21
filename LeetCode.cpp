// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        const int sz = s.size();

        for (int i = 0; i < sz; ++i) {
            if (s[i] == '?') {
                s[i] = 'a';

                while ((i > 0 && s[i] == s[i - 1]) || (i < sz - 1 && s[i] == s[i + 1])) {
                    ++s[i];
                }
            }
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