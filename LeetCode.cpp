// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int left = 0, right = 0;

        for (int i = 1, sz = s.size(); i < sz; ++i) {
            for (int l = i - 1, r = i; l >= 0 && r < sz && s[l] == s[r]; --l, ++r) {
                if (r - l + 1 > len) {
                    len = r - l + 1;
                    left = l;
                    right = r;
                }
            }

            for (int l = i - 1, r = i + 1; l >= 0 && r < sz && s[l] == s[r]; --l, ++r) {
                if (r - l + 1 > len) {
                    len = r - l + 1;
                    left = l;
                    right = r;
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
