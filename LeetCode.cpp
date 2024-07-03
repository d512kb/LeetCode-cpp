// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;

        int a = 0;
        int b = 1;
        int c = 1;

        for (int i = 3; i <= n; ++i) {
            int newC = a + b + c;
            a = b;
            b = c;
            c = newC;
        }

        return c;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}