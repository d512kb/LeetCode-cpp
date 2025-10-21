// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                ++opened;
            }
            else if (c == ')') {
                --opened;
            }
            ans = max(ans, opened);
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