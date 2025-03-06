// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class SeatManager {
public:
    SeatManager(int n) : m_maxReserved(0) {

    }

    int reserve() {
        if (!m_returned.empty()) {
            int seat = m_returned.top();
            m_returned.pop();
            return seat;
        }

        return ++m_maxReserved;
    }

    void unreserve(int seatNumber) {
        m_returned.push(seatNumber);
    }
private:
    int m_maxReserved;
    priority_queue<int, vector<int>, greater<>> m_returned;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}