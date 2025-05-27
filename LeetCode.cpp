// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) : m_size(maxSize) {
        m_data.reserve(m_size);
    }

    void push(int x) {
        if (m_data.size() < m_size) {
            m_data.push_back(x);
        }
    }

    int pop() {
        if (m_data.empty()) { return -1; }

        int result = m_data.back();
        m_data.pop_back();

        return result;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < m_data.size(); ++i) {
            m_data[i] += val;
        }
    }

private:
    const size_t m_size;
    vector<int> m_data;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}