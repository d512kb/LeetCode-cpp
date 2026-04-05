// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int cnt = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] == s[i]) {
                if (++cnt > ans) {
                    ans = cnt;
                }
            }
            else {
                cnt = 1;
            }
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