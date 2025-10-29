// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = time / (n - 1);
        int pos = time % (n - 1);

        if (cycle % 2 == 0) {
            return pos + 1;
        }

        return n - pos;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}