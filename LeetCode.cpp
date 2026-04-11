// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() > b.size()) { return a.size(); }

        return a == b ? -1 : b.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}