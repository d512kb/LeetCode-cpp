// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        array<char, 26> pos{};

        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'] = i;
        }

        int ans = 0;

        for (int i = 0; i < t.size(); ++i) {
            ans += abs(i - pos[t[i] - 'a']);
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