// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = 1;

        while (mask < num) {
            mask = (mask << 1) + 1;
        }

        return mask - num;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}