// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int diffChar = 0;

        for (int i = 0; i < s.size(); ++i) {
            diffChar += t[i] - s[i];
        }

        return diffChar + t.back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}