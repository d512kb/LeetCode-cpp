// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class FreqStack {
public:
    FreqStack() {

    }

    void push(int val) {
        int freq = m_freqMap[val]++;

        if (m_freqToValues.size() == freq) {
            m_freqToValues.emplace_back(1, val);
            return;
        }

        m_freqToValues[freq].push_back(val);
    }

    int pop() {
        if (m_freqToValues.back().empty()) { m_freqToValues.pop_back(); }

        int val = m_freqToValues.back().back();
        m_freqToValues.back().pop_back();
        --m_freqMap[val];
        return val;
    }
private:
    unordered_map<int, int> m_freqMap;
    deque<vector<int>> m_freqToValues;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}