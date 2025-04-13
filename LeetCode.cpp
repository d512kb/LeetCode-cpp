// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        array<int, 26> charCount{};
        for (char c : s) { ++charCount[c - 'a']; }

        string result(s.size(), 0);

        int aIndex = 0;
        int bIndex = s.size() - 1;

        for (int i = 0; i < 26; ++i) {
            while (charCount[i] > 1) {
                result[aIndex++] = i + 'a';
                result[bIndex--] = i + 'a';
                charCount[i] -= 2;
            }

            if (charCount[i] == 1) {
                result[s.size() / 2] = i + 'a';
                --charCount[i];
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}