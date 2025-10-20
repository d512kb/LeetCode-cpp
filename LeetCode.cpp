// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto iter = find(word.begin(), word.end(), ch);

        if (iter != word.end()) {
            reverse(word.begin(), iter + 1);
        }

        return word;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}