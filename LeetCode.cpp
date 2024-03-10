// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {

    }

    int get(int key) {
        auto iter = m_data.find(key);

        if (iter != m_data.end()) {
            iter->second.second = updateCache(iter->second.second);
            return iter->second.first;
        }

        return -1;
    }

    void put(int key, int value) {
        auto iter = m_data.find(key);

        if (iter != m_data.end()) {
            iter->second.first = value;
            iter->second.second = updateCache(iter->second.second);
        } else {
            if (m_data.size() == m_capacity) {
                m_data.erase(m_cache.back());
                m_cache.pop_back();
            }

            m_cache.push_front(key);
            m_data.insert({ key, {value, m_cache.begin()} });
        }
    }

private:
    list<int>::iterator updateCache(const list<int>::iterator& iter) {
        m_cache.splice(m_cache.begin(), m_cache, iter);

        return m_cache.begin();
    }
private:
    unordered_map<int, pair<int, list<int>::iterator>> m_data;
    list<int> m_cache;
    int m_capacity;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
