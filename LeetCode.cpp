// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> charPositions(26);

        for (int i = 0; i < 26; ++i) {
            charPositions[order[i] - 'a'] = i;
        }

        return is_sorted(words.begin(), words.end(), [&charPositions](const string& a, const string& b) {
            return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [&charPositions](char a, char b) { return charPositions[a - 'a'] < charPositions[b - 'a']; });
        });
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}