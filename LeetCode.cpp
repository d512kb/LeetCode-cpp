// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int64_t result = 0;
        int zeroesAhead = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++zeroesAhead;
            } else {
                result += zeroesAhead;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}