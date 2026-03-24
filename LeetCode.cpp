// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) { return false; }
        bool vowel = false;
        bool consonant = false;

        for (char c : word) {
            if (!isalnum(c)) { return false; }
            if (isalpha(c)) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    vowel = true;
                }
                else {
                    consonant = true;
                }
            }
        }

        return vowel && consonant;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}