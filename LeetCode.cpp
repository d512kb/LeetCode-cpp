// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (end - start > 0) { ++ans; }
                start = end = i + 1;
            }
            else {
                end = i + 1;
            }
        }

        if (end - start > 0) { ++ans; }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}