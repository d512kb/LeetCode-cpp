// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int start = 0; start < s.size(); start += 2 * k) {
            if (start + k <= s.size()) {
                reverse(s.begin() + start, s.begin() + start + k);
            }
            else {
                reverse(s.begin() + start, s.end());
            }
        }

        return s;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}