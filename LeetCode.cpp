// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            auto from = s.find(c);
            auto to = s.find_last_of(c);

            if (from == string::npos) { continue; }
            array<char, 26> diffChars{};

            for (auto k = from + 1; k < to; ++k) {
                diffChars[s[k] - 'a'] = 1;
            }
            ans += count(diffChars.begin(), diffChars.end(), 1);
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