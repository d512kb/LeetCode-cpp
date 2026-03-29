// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        auto caps = count_if(word.begin(), word.end(), [](char c) { return isupper(c); });

        return caps == 0 || (caps == 1 && isupper(word[0])) || caps == word.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}