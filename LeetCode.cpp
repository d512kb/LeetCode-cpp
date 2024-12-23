// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int bCounter = 0;
        int ans = 0;

        for (char c : s) {
            if (c == 'b') {
                ++bCounter;
            } else if (bCounter > 0) {
                ++ans;
                --bCounter;
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}