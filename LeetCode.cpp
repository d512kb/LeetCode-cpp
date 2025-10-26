// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        size_t start = 0;
        size_t end = 0;

        while ((end = text.find(' ', start)) != string::npos) {
            auto s = text.substr(start, end - start);
            if (find_first_of(s.begin(), s.end(), brokenLetters.begin(), brokenLetters.end()) == s.end()) {
                ++ans;
            }
            start = end + 1;
        }

        auto s = text.substr(start);
        if (find_first_of(s.begin(), s.end(), brokenLetters.begin(), brokenLetters.end()) == s.end()) {
            ++ans;
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