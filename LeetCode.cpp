// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> monthDays{ 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
        vector<string> weekDays{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

        int shift = year == 1971 ? 0 : (year - 1972) / 4 + 1;
        if (year == 2100 || (year % 4 == 0 && month <= 2 && day <= 29)) { --shift; }

        int dayNumber = (year - 1971) * 365 + monthDays[month] + day + shift - 1;

        return weekDays[(dayNumber + 5) % 7];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}