// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = s[i - 1] + s[i] - '0';
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