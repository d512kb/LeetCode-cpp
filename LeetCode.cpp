// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() : m_first(1) {
    }

    int popSmallest() {
        if (m_usedNums.empty()) {
            return m_first++;
        }

        int s = *m_usedNums.begin();
        m_usedNums.erase(m_usedNums.begin());
        return s;
    }

    void addBack(int num) {
        if (num < m_first) {
            m_usedNums.insert(num);
        }
    }
private:
    set<int> m_usedNums;
    int m_first;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}