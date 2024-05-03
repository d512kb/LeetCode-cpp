// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int a = x;
        long b = 0;

        while (a) {
            b = b * 10 + a % 10;
            a /= 10;
        }

        return x >= 0 && b == x;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
