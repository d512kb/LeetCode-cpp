// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long charCount = count(s.begin(), s.end(), c);

        // first char with itself, second char with itself and previous, etc.
        return charCount * (charCount + 1) / 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}