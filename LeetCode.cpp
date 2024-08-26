// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;

        while (a || b || c) {
            char v = (a & 1) + (b & 1);

            if (c & 1) {
                result += !v;
            } else {
                result += v;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}