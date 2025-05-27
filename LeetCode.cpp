// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) : m_size(k), m_capacity(k), m_begin(0), m_end(0), m_data(k) {

    }

    bool insertFront(int value) {
        if (isFull()) { return false; }
        --m_capacity;

        m_begin = (m_begin - 1 + m_size) % m_size;
        m_data[m_begin] = value;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) { return false; }
        --m_capacity;

        m_data[m_end] = value;
        m_end = (m_end + 1) % m_size;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) { return false; }
        ++m_capacity;

        m_begin = (m_begin + 1) % m_size;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) { return false; }
        ++m_capacity;

        m_end = (m_end - 1 + m_size) % m_size;

        return true;
    }

    int getFront() const {
        if (isEmpty()) { return -1; }

        return m_data[m_begin];
    }

    int getRear() const {
        if (isEmpty()) { return -1; }

        return m_data[(m_end - 1 + m_size) % m_size];
    }

    inline bool isEmpty() const {
        return m_capacity == m_size;
    }

    inline bool isFull() const {
        return m_capacity == 0;
    }

private:
    const size_t m_size;
    int m_capacity;
    int m_begin;
    int m_end;
    vector<int> m_data;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}