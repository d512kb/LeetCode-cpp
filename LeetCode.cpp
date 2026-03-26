// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        return min(x, y / 4) % 2 ? "Alice" : "Bob";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}