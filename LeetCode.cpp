// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int result = count(s.begin(), s.end(), '0');
        int val = 0;

        for (int i = s.size() - 1, offset = 0; i >= 0; --i, ++offset) {
            if (val > k - (1 << offset)) { break; }

            if (s[i] == '1') {
                val += 1 << offset;
                ++result;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}