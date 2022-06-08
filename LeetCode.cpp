// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1])
                return 2;
        }

        return 1;
    }
};

int main() {

    Solution sol;

    sol.removePalindromeSub("abaaba");

    return 0;
}
