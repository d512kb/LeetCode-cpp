// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) { return "0"; }

        string result;
        char counter = 0;

        while (n) {
            result.push_back('0' + n % 10);
            n /= 10;

            if (++counter == 3) {
                result.push_back('.');
                counter = 0;
            }
        }

        if (result.back() == '.') { result.pop_back(); }
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