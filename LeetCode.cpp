// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while (columnNumber > 0) {
            --columnNumber;
            result.push_back('A' + columnNumber % 26);
            columnNumber /= 26;
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