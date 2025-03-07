// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int n = num / 2; n <= num; ++n) {
            int val = n;
            int nRev = 0;

            while (val) {
                nRev = nRev * 10 + val % 10;
                val /= 10;
            }

            if (n + nRev == num) { return true; }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}