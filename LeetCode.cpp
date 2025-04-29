// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        array<int, 26> charCount{};

        for (char c : word) {
            ++charCount[c - 'a'];
        }

        sort(charCount.rbegin(), charCount.rend());
        int ans = 0;

        for (int i = 0; i < 26; ++i) {
            ans += charCount[i] * (i / 8 + 1);
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