// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class TimeMap {
    struct TimestampComparer {
        bool operator()(auto& a, auto& b) const {
            return a.first > b.first;
        }
    };

public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        m_map[key].emplace(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto iter = m_map.find(key);
        if (iter == m_map.end()) { return ""; }

        auto valueIter = iter->second.lower_bound({ timestamp, "" });

        if (valueIter == iter->second.end()) { return ""; }
        return valueIter->second;
    }
private:
    map<string, std::set<pair<int, string>, TimestampComparer>> m_map;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}