// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        array<int, 3> charCount{};

        for (char c : s) { ++charCount[c - 'a']; }
        if (*min_element(charCount.begin(), charCount.end()) < k) { return -1; }

        const int sz = s.size();
        int windowSize = 0;

        for (int left = 0, right = 0; right < sz; ++right) {
            char rc = s[right] - 'a';

            if (--charCount[rc] < k) {
                while (charCount[rc] < k) {
                    ++charCount[s[left++] - 'a'];
                }
            }

            windowSize = max(windowSize, right - left + 1);
        }

        return sz - windowSize;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}