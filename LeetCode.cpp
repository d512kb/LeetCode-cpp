// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        const int wordSz = words.front().size();

        sort(words.begin(), words.end(), [wordSz](const auto& word1, const auto& word2) {
            for (int i = 1; i < wordSz; ++i) {
                int a = word1[i] - word1[i - 1];
                int b = word2[i] - word2[i - 1];

                if (a != b) { return a < b; }
            }

            return false;
        });

        for (int i = 1; i < wordSz; ++i) {
            int a = words[0][i] - words[0][i - 1];
            int b = words[1][i] - words[1][i - 1];

            if (a != b) { return words.front(); }
        }

        return words.back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}