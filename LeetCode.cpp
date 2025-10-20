// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s);

        for (int i = 0; i < s.size(); ++i) {
            ans[indices[i]] = s[i];
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