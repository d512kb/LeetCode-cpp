// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycle = k / (n - 1);
        int pos = k % (n - 1);

        if (cycle % 2 == 0) {
            return pos;
        }

        return n - pos - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}