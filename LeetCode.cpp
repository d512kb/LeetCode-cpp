// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        return calcMinMoves(s, 0, s.size() - 1);
    }
private:
    int calcMinMoves(string& s, int a, int b) {
        if (a >= b) { return 0; }
        if (s[a] == s[b]) { return calcMinMoves(s, a + 1, b - 1); }

        int leftCh = a, rightCh = b;
        for (int i = b; i > a; --i) {
            if (s[i] == s[a]) {
                leftCh = i;
                break;
            }
        }

        for (int i = a; i < b; ++i) {
            if (s[i] == s[b]) {
                rightCh = i;
                break;
            }
        }

        if (b - leftCh < rightCh - a) { // it's cheaper to mirror the leftmost char
            for (int i = leftCh; i < b; ++i) { swap(s[i], s[i + 1]); }
            return b - leftCh + calcMinMoves(s, a + 1, b - 1);
        } else {
            for (int i = rightCh; i > a; --i) { swap(s[i], s[i - 1]); }
            return rightCh - a + calcMinMoves(s, a + 1, b - 1);
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}