// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;

        int groupLen = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '-') { continue; }
            if (groupLen == k) { result.push_back('-'); groupLen = 0; }

            result.push_back(toupper(s[i]));
            ++groupLen;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}