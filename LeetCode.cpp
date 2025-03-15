// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int zeroCount = 0;
        int oneCount = 0;

        for (char c : s) {
            if (c == '0') { ++zeroCount; } else { ++oneCount; }
        }

        if (abs(zeroCount - oneCount) > 1) { return -1; }
        int ans = s.size();

        if (zeroCount == oneCount) {
            // start with 0
            ans = min(ans, calcWrongChars(s, '0') / 2);

            // start with 1
            ans = min(ans, calcWrongChars(s, '1') / 2);
        } else if (zeroCount > oneCount) {
            ans = min(ans, calcWrongChars(s, '0') / 2);
        } else {
            ans = min(ans, calcWrongChars(s, '1') / 2);
        }

        return ans;
    }
private:
    int calcWrongChars(const string& s, char startChar) {
        int wrongCharsCount = 0;

        for (char c : s) {
            if (c != startChar) { ++wrongCharsCount; }
            startChar = (startChar - '0' + 1) % 2 + '0';
        }

        return wrongCharsCount;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}