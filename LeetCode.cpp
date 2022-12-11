// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0))
            return false;

        int y{ 0 };

        while (x > y) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return x == y || x == y / 10;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    sol.isPalindrome(12321);

    PRINT_ELAPSED(timer);

    return 0;
}
