// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        m_pings.push(t);
        t -= 3000;

        while (t > m_pings.front()) {
            m_pings.pop();
        }

        return m_pings.size();
    }
private:
    queue<int> m_pings;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}