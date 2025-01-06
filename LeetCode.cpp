// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;

        for (int n : nums) {
            if (n == 0) { return 0; }
            if (n < 0) { ++neg; }
        }

        return 1 - 2 * (neg % 2);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}