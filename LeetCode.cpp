// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int diffs = 0;

        while (left < right) {
            if (s[left] != s[right]) {
                for (int l = left + 1, r = right; l < r; ++l, --r) {
                    if (s[l] != s[r]) {
                        ++diffs;
                        break;
                    }
                }

                for (int l = left, r = right - 1; l < r; ++l, --r) {
                    if (s[l] != s[r]) {
                        ++diffs;
                        break;
                    }
                }

                break;
            }

            ++left;
            --right;
        }

        return diffs < 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}