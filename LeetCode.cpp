// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        array<int, 26> charCount{};
        array<int, 26> targetCharCount{};

        for (char c : s) {
            ++charCount[c - 'a'];
        }

        for (char c : target) {
            ++targetCharCount[c - 'a'];
        }

        int ans = numeric_limits<int>::max();

        for (int i = 0; i < targetCharCount.size(); ++i) {
            if (targetCharCount[i] == 0) { continue; }

            ans = min(ans, charCount[i] / targetCharCount[i]);
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