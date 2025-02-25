// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;

        if (num1.size() > num2.size()) {
            swap(num1, num2);
        }

        int num1pos = num1.size() - 1;
        int num2pos = num2.size() - 1;
        char carry = 0;

        for (; num1pos >= 0; --num1pos, --num2pos) {
            char add = num1[num1pos] - '0' + num2[num2pos] - '0' + carry;
            result += (add % 10) + '0';
            carry = add / 10;
        }

        for (; num2pos >= 0; --num2pos) {
            char add = num2[num2pos] - '0' + carry;
            result += (add % 10) + '0';
            carry = add / 10;
        }

        if (carry == 1) {
            result += '1';
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