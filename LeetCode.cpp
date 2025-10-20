// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int x = num;
        int ans = 0;

        while (x) {
            if (num % (x % 10) == 0) {
                ++ans;
            }
            x /= 10;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}