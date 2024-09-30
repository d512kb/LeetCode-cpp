// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        int ans = sz; // every single char

        for (int i = 0; i < sz; ++i) {
            for (int l = i - 1, r = i + 1; l >= 0 && r < sz && s[l] == s[r]; --l, ++r) { ++ans; }
            for (int l = i, r = i + 1; l >= 0 && r < sz && s[l] == s[r]; --l, ++r) { ++ans; }
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}