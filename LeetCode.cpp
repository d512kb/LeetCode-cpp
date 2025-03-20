// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        const int sz = s.size();
        int result = 0;
        int prevLen = 0;
        int len = 1;

        for (int i = 1; i < sz; ++i) {
            if (s[i - 1] == s[i]) {
                ++len;
            } else {
                result += min(prevLen, len);
                prevLen = exchange(len, 1);
            }
        }

        return result + min(prevLen, len);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}