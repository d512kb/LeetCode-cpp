// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        array<int, 26> charCount{};

        for (char c : s) { ++charCount[c - 'a']; }
        int maxCount = *max_element(charCount.begin(), charCount.end());

        string result;

        for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
            if (charCount[*iter - 'a'] == maxCount) {
                result.push_back(*iter);
                charCount[*iter - 'a'] = 0;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}