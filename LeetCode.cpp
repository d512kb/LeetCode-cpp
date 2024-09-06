// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        int a = 0, b = 0;
        int lenMax = 0;
        bitset<256> chars;

        for (b; b < sz; ++b) {
            char c = s[b];

            if (chars[c]) {
                lenMax = max(lenMax, b - a);

                for (; s[a] != c; ++a) {
                    chars[s[a]] = 0;
                }

                ++a;
            }

            chars[c] = 1;
        }

        return max(lenMax, b - a);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}