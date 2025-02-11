// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) :
        m_encodedData(encoding),
        m_currentIter(m_encodedData.begin()) {

    }

    int next(int n) {
        while (m_currentIter != m_encodedData.end()) {
            if (*m_currentIter >= n) {
                *m_currentIter -= n;
                return *(m_currentIter + 1);
            }

            n -= *m_currentIter;
            m_currentIter += 2;
        }

        return -1;
    }
private:
    vector<int> m_encodedData;
    vector<int>::iterator m_currentIter;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}