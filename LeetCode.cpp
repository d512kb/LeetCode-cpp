// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        size_t canObtain = 0;
        int ans = 0;

        for (int c : coins) {
            while ((canObtain + 1) < c) {
                canObtain = 2 * canObtain + 1;
                ++ans;
            }

            canObtain += c;
        }

        while (canObtain < target) {
            canObtain = 2 * canObtain + 1;
            ++ans;
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