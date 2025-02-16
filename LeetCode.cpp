// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    int rand7() { return 0; }
public:
    int rand10() {
        int val = 40;
        while (val >= 40) { val = (rand7() - 1) * 7 + rand7() - 1; }

        return val % 10 + 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}