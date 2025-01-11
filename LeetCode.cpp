// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class LFUCache {
    using FrequencyItems = list<pair<int, int>>;
    struct Frequency {
        int freq;
        FrequencyItems::iterator iter;
    };
public:
    LFUCache(int capacity) : m_capacity(capacity), m_minFreq(0) {

    }

    int get(int key) {
        auto value = findValue(key);
        if (value) { return *value; }

        return -1;
    }

    void put(int key, int value) {
        auto val = findValue(key);

        if (val) {
            val->get() = value;
            return;
        }

        if (m_keyToFreq.size() == m_capacity) {
            auto& freqList = m_freqToItems[m_minFreq];
            m_keyToFreq.erase(freqList.front().first);
            freqList.pop_front();
            if (freqList.empty()) { m_freqToItems.erase(m_minFreq); }
        }

        m_minFreq = 0;
        auto& freqList = m_freqToItems[0];
        m_keyToFreq[key].iter = freqList.emplace(freqList.end(), key, value);
    }
private:
    int m_capacity;
    int m_minFreq;
    unordered_map<int, Frequency> m_keyToFreq;
    unordered_map<int, FrequencyItems> m_freqToItems;

    std::optional<reference_wrapper<int>> findValue(int key) {
        auto keyIter = m_keyToFreq.find(key);
        if (keyIter == m_keyToFreq.end()) { return std::nullopt; }

        auto& [freq, iter] = keyIter->second;
        auto& curList = m_freqToItems[freq];
        auto& nextList = m_freqToItems[freq + 1];

        nextList.splice(nextList.end(), curList, iter);
        iter = --nextList.end();

        if (curList.empty()) {
            m_freqToItems.erase(freq);
            if (m_minFreq == freq) { ++m_minFreq; }
        }

        ++freq;
        return iter->second;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}