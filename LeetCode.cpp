// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int op = 0;
        string tempStr;
        string result;

        for (char c : s) {
            if (c == '(') {
                ++op;
                tempStr.push_back('(');
            }
            else {
                if (--op == 0) {
                    result.append(tempStr.substr(1));
                    tempStr.clear();
                }
                else {
                    tempStr.push_back(')');
                }
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