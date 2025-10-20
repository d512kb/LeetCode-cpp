// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        array<char, 26> table;
        unordered_set<char> usedChars;

        for (char c : key) {
            if (c == ' ') { continue; }

            if (usedChars.insert(c).second) {
                table[c - 'a'] = usedChars.size() - 1;
            }
        }

        for (char& c : message) {
            if (c == ' ') { continue; }

            c = table[c - 'a'] + 'a';
        }

        return message;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}