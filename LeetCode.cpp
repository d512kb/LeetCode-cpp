// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) { return "0"; }

        constexpr auto codeTable("0123456789abcdef");
        string result;
        uint32_t n = num;

        while (n) {
            result.push_back(codeTable[n & 0b1111]);
            n >>= 4;
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