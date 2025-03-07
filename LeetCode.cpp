// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        array<int, 'z' + 1> charCount;

        for (char c : s) {
            ++charCount[c];
        }

        int ans = 0;
        for (int count : charCount) {
            ans += count & 0xfffffffe;
        }

        if (ans < s.size()) { ++ans; }
        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}