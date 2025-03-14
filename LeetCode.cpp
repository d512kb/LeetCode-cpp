// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;

        int zeroesBefore = 0;
        int onesBefore = 0;
        long long zeroChains = 0;
        long long oneChains = 0;

        for (char c : s) {
            if (c == '1') {
                ans += zeroChains;
                oneChains += zeroesBefore;
                ++onesBefore;
            } else {
                ans += oneChains;
                zeroChains += onesBefore;
                ++zeroesBefore;
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