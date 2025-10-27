// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        nth_element(prices.begin(), prices.begin(), prices.end());
        int min1 = prices[0];
        nth_element(prices.begin(), prices.begin() + 1, prices.end());
        int min2 = prices[1];

        if (min1 + min2 > money) { return money; }

        return money - (min1 + min2);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}