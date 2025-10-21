// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int startPos = 0;
        int spacePos = 0;
        string result;

        while ((spacePos = s.find(' ', startPos)) != string::npos) {
            auto word = s.substr(startPos, spacePos - startPos);
            reverse(word.begin(), word.end());
            result += word + " ";
            startPos = spacePos + 1;
        }

        string word = s.substr(startPos);
        reverse(word.begin(), word.end());
        result += word;

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}