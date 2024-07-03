// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;

        while (--n >= 0) {
            a = exchange(b, a + b);
        }

        return a;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}