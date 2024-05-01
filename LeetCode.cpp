// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        m_maxHeap.push(numeric_limits<int>::min());
        m_minHeap.push(numeric_limits<int>::max());
    }

    void addNum(int num) {
        if (num > m_minHeap.top()) {
            m_minHeap.push(num);
        } else {
            m_maxHeap.push(num);
        }

        if (m_minHeap.size() > m_maxHeap.size()) {
            m_maxHeap.push(m_minHeap.top());
            m_minHeap.pop();
        } else if (m_maxHeap.size() - m_minHeap.size() == 2) {
            m_minHeap.push(m_maxHeap.top());
            m_maxHeap.pop();
        }
    }

    double findMedian() {
        if (m_minHeap.size() == m_maxHeap.size()) {
            return (m_maxHeap.top() + m_minHeap.top()) / 2.0;
        } else {
            return m_maxHeap.top();
        }
    }
private:
    priority_queue<int> m_maxHeap;
    priority_queue<int, vector<int>, greater<int>> m_minHeap;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
