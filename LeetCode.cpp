// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        size_t startPos = 0;

        for (const auto& word : words) {
            if (startPos == s.size()) { return true; }

            if (s.find(word, startPos) == startPos) {
                startPos += word.size();
            }
            else {
                return false;
            }
        }

        return startPos == s.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}