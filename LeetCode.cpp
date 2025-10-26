// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) { return false; }

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != words[i][0]) { return false; }
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