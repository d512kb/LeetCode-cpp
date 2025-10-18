// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            ans += ('z' - s[i] + 1) * (i + 1);
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}