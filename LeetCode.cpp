// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        using SubstringLengths = priority_queue<int, vector<int>, greater<>>;
        const SubstringLengths defaultLengths(SubstringLengths::value_compare(), { 0, 0, 0 });
        vector<SubstringLengths> substrings(26, defaultLengths);
        int substringLen = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++substringLen;
            } else {
                auto& substr = substrings[s[i - 1] - 'a'];

                if (substringLen > substr.top()) {
                    substr.pop();
                    substr.push(substringLen);
                }

                substringLen = 1;
            }
        }

        if (substringLen > substrings[s.back() - 'a'].top()) {
            substrings[s.back() - 'a'].pop();
            substrings[s.back() - 'a'].push(substringLen);
        }

        int ans = 0;

        for (auto& substr : substrings) {
            ans = max(ans, substr.top());
            substr.pop();

            int a = substr.top();
            substr.pop();
            int b = substr.top();

            if (a == b) {
                ans = max(ans, a - 1);
            } else {
                ans = max(ans, max(a, b - 2));
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}