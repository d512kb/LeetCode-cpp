// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int sz = s.size();
        int chars[26]{};
        int mainChars = 0;
        int left = 0;
        int right = 0;

        while (right < sz) {
            mainChars = max(mainChars, ++chars[s[right++] - 'A']);

            if (right - left - mainChars > k) {
                --chars[s[left++] - 'A'];
            }
        }

        return right - left;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}