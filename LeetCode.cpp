// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        int c = n;

        for (int i = 2; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
