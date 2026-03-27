// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;

        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ++v;
            }
            else if (isalpha(ch)) {
                ++c;
            }
        }

        return c > 0 ? v / c : 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}