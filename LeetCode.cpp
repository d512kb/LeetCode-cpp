// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        const int firstWeek = 7 * 8 / 2;
        const int weeks = n / 7;
        const int lastWeek = firstWeek + 7 * (weeks - 1);

        const int weeksMoney = (firstWeek + lastWeek) * weeks / 2;

        const int daysLeft = n % 7;
        const int monday = weeks + 1;
        const int lastDay = monday + daysLeft - 1;

        const int daysMoney = (monday + lastDay) * daysLeft / 2;

        return weeksMoney + daysMoney;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}