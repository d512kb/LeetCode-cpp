// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
private:
    class DSet {
        vector<int> m_parent;

    public:
        DSet(int n) : m_parent(n, -1) {};

        int findParent(int n) {
            if (m_parent[n] < 0) { return n; }
            return m_parent[n] = findParent(m_parent[n]);
        }

        void join(int a, int b) {
            int parentA = findParent(a);
            int parentB = findParent(b);

            if (parentA == parentB) { return; }

            if (m_parent[parentA] < m_parent[parentB]) {
                m_parent[parentA] += m_parent[parentB];
                m_parent[parentB] = parentA;
            }
            else {
                m_parent[parentB] += m_parent[parentA];
                m_parent[parentA] = parentB;
            }
        }
    };

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSet dset(n);

        for (const auto& edge : edges) {
            dset.join(edge[0], edge[1]);
        }

        return dset.findParent(source) == dset.findParent(destination);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}