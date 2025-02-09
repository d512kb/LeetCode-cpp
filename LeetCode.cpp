// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int startTime, int endTime) {
        auto nextEvent = m_events.lower_bound(endTime);

        if (nextEvent == m_events.begin() || prev(nextEvent)->second <= startTime) {
            m_events[startTime] = endTime;
            return true;
        }

        return false;
    }
private:
    map<int, int> m_events;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}