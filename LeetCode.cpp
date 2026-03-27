// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] > s[i] && (s[i - 1] - '0') % 2 == (s[i] - '0') % 2) {
                swap(s[i - 1], s[i]);
                return s;
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