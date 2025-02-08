// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    class DSet {
    public:
        explicit DSet(size_t size) : m_parent(size, -1) {

        }

        int find(int value) {
            if (m_parent[value] < 0) { return value; }
            return m_parent[value] = find(m_parent[value]);
        }

        void erase(int value) {
            m_parent[value] = -1;
        }

        void join(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) { return; }

            auto& parentA = m_parent[a];
            auto& parentB = m_parent[b];

            if (parentA < parentB) { // size, negative
                parentA += parentB;
                parentB = a;
            } else {
                parentB += parentA;
                parentA = b;
            }
        }
    private:
        vector<int> m_parent;
    };
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto cmp = [](const auto& m1, const auto& m2) { return m1[2] < m2[2]; };
        sort(meetings.begin(), meetings.end(), cmp);

        DSet dset(n);
        dset.join(0, firstPerson);

        auto startTime = meetings.begin();
        while (startTime != meetings.end()) {
            int currentTime = (*startTime)[2];
            auto endTime = startTime;

            for (endTime; endTime != meetings.end() && (*endTime)[2] == currentTime; ++endTime) {
                const auto& met = *endTime;
                dset.join(met[0], met[1]);
            }

            int secretKeeper = dset.find(0);

            for (startTime; startTime != endTime; ++startTime) {
                int part1 = (*startTime)[0];
                int part2 = (*startTime)[1];

                if (dset.find(part1) != secretKeeper) {
                    dset.erase(part1);
                    dset.erase(part2);
                }
            }
        }

        int secretKeeper = dset.find(0);
        vector<int> result;

        while (--n >= 0) {
            if (dset.find(n) == secretKeeper) { result.push_back(n); }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}