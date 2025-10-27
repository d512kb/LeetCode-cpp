// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0;
        int col = 0;

        for (const auto& comm : commands) {
            if (comm[0] == 'U') {
                --row;
            }
            else if (comm[0] == 'R') {
                ++col;
            }
            else if (comm[0] == 'D') {
                ++row;
            }
            else if (comm[0] == 'L') {
                --col;
            }
        }

        return row * n + col;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}