// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result(s.size() + 1);

        int decr = count(s.begin(), s.end(), 'D');
        int incr = decr;
        result[0] = incr;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'D') {
                result[i + 1] = --decr;
            }
            else {
                result[i + 1] = ++incr;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}