// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) : m_currentSnapshot(0), m_data(length, { {0, 0} }) {

    }

    void set(int index, int val) {
        auto& lastVal = m_data[index].back();

        if (lastVal.second == m_currentSnapshot) {
            lastVal.first = val;
        } else if (lastVal.first != val) {
            m_data[index].emplace_back(val, m_currentSnapshot);
        }
    }

    int snap() {
        return m_currentSnapshot++;
    }

    int get(int index, int snap_id) {
        auto& vals = m_data[index];

        return lower_bound(vals.rbegin(), vals.rend(), snap_id, [](auto& v, int snap) {
            return v.second > snap;
        })->first;
    }
private:
    int m_currentSnapshot;
    vector<vector<pair<int, int>>> m_data; // pair<value, snapshot_id>
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}