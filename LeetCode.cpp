// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int> revertPositions;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                revertPositions.push(result.size());
                continue;
            }
            if (s[i] == ')') {
                reverse(result.begin() + revertPositions.top(), result.end());
                revertPositions.pop();
                continue;
            }

            result.push_back(s[i]);
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