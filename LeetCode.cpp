// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        auto iter = find(s.begin(), s.end(), '0');
        iter = find(iter, s.end(), '1');

        return iter == s.end();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}