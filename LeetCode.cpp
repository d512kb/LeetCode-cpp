// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() :
        m_rndEngine(random_device()())
    {
    }

    bool insert(int val) {
        auto result = m_indexes.insert({ val, 0 });

        if (result.second) {
            m_data.push_back(val);
            m_indexes[val] = m_data.size() - 1;
            m_intDistribution.param(decltype(m_intDistribution.param())(0, m_data.size() - 1));
        }

        return result.second;
    }

    bool remove(int val) {
        auto iter = m_indexes.find(val);

        if (iter != m_indexes.end()) {
            m_data[iter->second] = m_data.back();
            m_indexes[m_data.back()] = iter->second;
            m_data.pop_back();
            m_indexes.erase(iter);
            m_intDistribution.param(decltype(m_intDistribution.param())(0, m_data.size() - 1));

            return true;
        }

        return false;
    }

    int getRandom()
    {
        return m_data[m_intDistribution(m_rndEngine)];
    }

private:
    unordered_map<int, int> m_indexes;
    vector<int> m_data;
    default_random_engine m_rndEngine;
    uniform_int_distribution<int> m_intDistribution;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
