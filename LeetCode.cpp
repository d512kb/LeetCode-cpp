// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class MyHashMap {
    using Bucket = vector<pair<int, int>>;
    using HashData = vector<Bucket>;
public:
    MyHashMap() : m_data(1 << 10) {

    }

    void put(int key, int value) {
        auto item = findItem(key);
        if (item.second == item.first.end()) { item.first.emplace_back(key, value); } else { item.second->second = value; }
    }

    int get(int key) {
        auto item = findItem(key);
        if (item.second == item.first.end()) { return -1; }
        return item.second->second;
    }

    void remove(int key) {
        auto item = findItem(key);
        if (item.second != item.first.end()) { item.first.erase(item.second); }
    }
private:
    inline int hash(int v) {
        return v >> 10;
    }

    pair<Bucket&, Bucket::iterator> findItem(int key) {
        auto& values = m_data[hash(key)];

        return { ref(values), find_if(values.begin(), values.end(), [key](const auto& val) { return val.first == key; }) };
    }

    HashData m_data;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}