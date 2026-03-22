// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        vector<int> daysCoded(days);

        partial_sum(days.begin(), days.end(), daysCoded.begin());

        auto codeDate = [&](const string& date) -> int {
            return daysCoded[stoi(date.substr(0, 2)) - 1] + stoi(date.substr(3, 2));
            };

        int arriveAliceCoded = codeDate(arriveAlice);
        int leaveAliceCoded = codeDate(leaveAlice);
        int arriveBobCoded = codeDate(arriveBob);
        int leaveBobCoded = codeDate(leaveBob);

        if (arriveBobCoded >= arriveAliceCoded && arriveBobCoded <= leaveAliceCoded) {
            return min(leaveBobCoded, leaveAliceCoded) - arriveBobCoded + 1;
        }
        else if (arriveAliceCoded >= arriveBobCoded && arriveAliceCoded <= leaveBobCoded) {
            return min(leaveBobCoded, leaveAliceCoded) - arriveAliceCoded + 1;
        }
        else {
            return 0;
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}