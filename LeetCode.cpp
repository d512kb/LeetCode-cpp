// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        int ans = 0;

        size_t start = 0;
        size_t stop = 0;

        while ((stop = sentence.find(' ', start)) != string::npos) {
            if (isValidWord(sentence, start, stop)) { ++ans; }
            start = stop + 1;
        }

        if (isValidWord(sentence, start, sentence.size())) { ++ans; }

        return ans;
    }
private:
    bool isValidWord(const string& word, size_t start, size_t stop) {
        if (start == stop) { return false; }

        size_t hyphenCount = 0;

        for (size_t i = start; i < stop; ++i) {
            char c = word[i];

            if (isdigit(c)) { return false; }
            if (c == '-') {
                if (++hyphenCount > 1) { return false; }
                if (i == start || i == stop - 1) { return false; }
                if (!isalpha(word[i - 1]) || !isalpha(word[i + 1])) { return false; }
            }
            else if (c == '.' || c == ',' || c == '!') {
                if (i != stop - 1) { return false; }
            }
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