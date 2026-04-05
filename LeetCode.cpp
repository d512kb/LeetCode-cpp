// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        array<char, 10> count{};

        for (char c : s) { ++count[c - '0']; }

        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] != s[i] && count[s[i - 1] - '0'] == s[i - 1] - '0' && count[s[i] - '0'] == s[i] - '0') {
                return s.substr(i - 1, 2);
            }
        }

        return "";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}