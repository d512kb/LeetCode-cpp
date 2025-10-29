// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        array<int, 26> charCount{};
        array<int, 26> targetCharCount{};
        targetCharCount['b' - 'a'] = 1;
        targetCharCount['a' - 'a'] = 1;
        targetCharCount['l' - 'a'] = 2;
        targetCharCount['o' - 'a'] = 2;
        targetCharCount['n' - 'a'] = 1;

        for (char c : text) {
            ++charCount[c - 'a'];
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