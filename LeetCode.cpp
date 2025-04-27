// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<bool, 26> lowercaseChars{}, uppercaseChars{};

        for (char c : word) {
            if (isupper(c)) {
                uppercaseChars[c - 'A'] = true;
            } else {
                lowercaseChars[c - 'a'] = !uppercaseChars[c - 'a'];
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; ++i) {
            if (lowercaseChars[i] && uppercaseChars[i]) {
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