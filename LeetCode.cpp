// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        const int minLen = min(min(s1.size(), s2.size()), s3.size());
        const int totalLen = s1.size() + s2.size() + s3.size();
        int ans = totalLen;

        for (int i = 0; i < minLen; ++i) {
            if (s1[i] == s2[i] && s2[i] == s3[i]) {
                ans -= 3;
            }
            else {
                break;
            }
        }

        return ans == totalLen ? -1 : ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}