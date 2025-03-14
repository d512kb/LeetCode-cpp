// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> calc{ 0 }; // first item is a placeholder
        int num = 0;

        for (char c : s) {
            if (c == ' ') { continue; }

            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else { // it's time to use num
                int op = calc.back();

                if (op == '/' || op == '*') {
                    calc.pop_back();

                    if (op == '/') {
                        calc.back() /= num;
                    } else {
                        calc.back() *= num;
                    }
                } else {
                    calc.push_back(num);
                }

                num = 0;
                calc.push_back(c);
            }
        }

        int op = calc.back();
        if (op == '/' || op == '*') {
            calc.pop_back();

            if (op == '/') {
                calc.back() /= num;
            } else {
                calc.back() *= num;
            }
        } else {
            calc.push_back(num);
        }

        const int calcSz = calc.size();

        for (int i = 1; i + 2 < calcSz; i += 2) {
            int left = calc[i];
            int op = calc[i + 1];
            int& right = calc[i + 2];

            if (op == '+') {
                right = left + right;
            } else {
                right = left - right;
            }
        }

        return calc.back();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}