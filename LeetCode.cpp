// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> monthDays{ 0, 31, 59 ,90, 120, 151, 181, 212, 243, 273, 304, 334 };

        struct Date {
            int year;
            int month;
            int day;
        };

        auto parseDate = [](const string& date) -> Date {
            Date d;

            from_chars(&date[0], &date[4], d.year);
            from_chars(&date[5], &date[7], d.month);
            from_chars(&date[8], &date[10], d.day);

            return d;
            };

        auto calcDays = [&](const Date& date) {
            int days = (date.year - 1900) * 365;
            days += monthDays[date.month - 1];
            days += date.day;

            days += (date.year - 1900) / 4;
            if (date.year == 2100 || (date.year % 4 == 0 && date.month < 3)) {
                --days;
            }

            return days;
            };

        auto date1Parsed = parseDate(date1);
        auto date2Parsed = parseDate(date2);

        auto days1 = calcDays(date1Parsed);
        auto days2 = calcDays(date2Parsed);

        return abs(days1 - days2);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}