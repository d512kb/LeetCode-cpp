// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) { return 0; }

        return bit_width(static_cast<uint32_t>(num)) + popcount(static_cast<uint32_t>(num)) - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}