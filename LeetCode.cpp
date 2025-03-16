// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        string word(words.front());
        sort(word.begin(), word.end());

        auto wordStart = word.begin();
        auto wordEnd = word.end();

        for (string& s : words) {
            sort(s.begin(), s.end());
            wordEnd = set_intersection(wordStart, wordEnd, s.begin(), s.end(), wordStart);
        }

        vector<string> result;
        for (; wordStart != wordEnd; ++wordStart) {
            result.emplace_back(1, *wordStart);
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