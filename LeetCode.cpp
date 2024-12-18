// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        // if n is odd, the diffs are 2 + 4 + 6 + ...
        // if n is even, the diffs are 1 + 3 + 5 + ...
        // after all the simplifications we can get the following formula

        return (n / 2) * (n / 2 + n % 2);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}