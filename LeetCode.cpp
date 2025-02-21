// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        const int sz = s.size();
        using MaxLengths = priority_queue<int, vector<int>, greater<>>;
        const MaxLengths defaultLengths(MaxLengths::value_compare(), { 0, 0, 0 });
        vector<MaxLengths> lengths(26, defaultLengths);

        int currLen = 1;
        for (int i = 1; i < sz; ++i) {
            if (s[i] == s[i - 1]) {
                ++currLen;
            } else {
                auto& maxLengths = lengths[s[i - 1] - 'a'];
                if (maxLengths.top() < currLen) {
                    maxLengths.pop();
                    maxLengths.push(currLen);
                }
                currLen = 1;
            }
        }

        auto& maxLengths = lengths[s.back() - 'a'];
        if (maxLengths.top() < currLen) {
            maxLengths.pop();
            maxLengths.push(currLen);
        }

        int result = 0;
        for (auto& len : lengths) {
            result = max(result, len.top());
            len.pop();

            int a = len.top();
            len.pop();
            int b = len.top();

            if (a == b) {
                result = max(result, a - 1);
            } else {
                result = max(result, max(a, b - 2));
            };
        }

        return result == 0 ? -1 : result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}