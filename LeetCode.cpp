// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        array<int, 100> domCount{};

        for (const auto& dom : dominoes) {
            if (dom[0] != dom[1]) {
                ans += domCount[dom[0] * 10 + dom[1]] + domCount[dom[1] * 10 + dom[0]];
            }
            else {
                ans += domCount[dom[0] * 10 + dom[1]];
            }

            ++domCount[dom[0] * 10 + dom[1]];
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