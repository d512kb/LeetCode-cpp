// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int numCount[10]{};
        for (char c : num) { ++numCount[c - '0']; }
        string leftPart;
        string center;

        for (int i = 9; i >= 0; --i) {
            if (i == 0 && leftPart.empty()) { if (center.empty()) { center.push_back('0'); }; break; }
            while (numCount[i] > 1) {
                leftPart.push_back(i + '0');
                numCount[i] -= 2;
            }
            if (numCount[i] > 0 && center.empty()) { center.push_back(i + '0'); }
        }

        if (!leftPart.empty()) {
            return leftPart + center + string(leftPart.rbegin(), leftPart.rend());
        }

        return center;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}