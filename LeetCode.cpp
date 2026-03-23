// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        vector<int> monthDays{ 0, 31, 59 ,90, 120, 151, 181, 212, 243, 273, 304, 334 };
        int year, month, day;

        from_chars(&date[0], &date[4], year);
        from_chars(&date[5], &date[7], month);
        from_chars(&date[8], &date[10], day);

        return monthDays[month - 1] + day + (month > 2 && year != 1900 && year % 4 == 0);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}