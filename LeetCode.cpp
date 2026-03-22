// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool ans = false;

        ans |= s1 == s2;
        swap(s1[0], s1[2]);
        ans |= s1 == s2;
        swap(s1[1], s1[3]);
        ans |= s1 == s2;
        swap(s1[0], s1[2]);
        ans |= s1 == s2;

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}