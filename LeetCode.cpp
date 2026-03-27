// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) { return "0"; }

        string result;
        bool minus = num < 0;

        if (minus) { num = -num; }

        while (num) {
            result.push_back('0' + num % 7);
            num /= 7;
        }

        if (minus) { result.push_back('-'); }

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