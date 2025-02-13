// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, -1);

        for (auto& edge : edges) {
            join(parent, edge[0], edge[1]);
        }

        int64_t allPairs = static_cast<int64_t>(n) * (n - 1) / 2;
        for (int par : parent) {
            if (par < 0) {
                allPairs -= static_cast<int64_t>(par) * (par + 1) / 2; // par is negative, so +
            }
        }

        return allPairs;
    }
private:
    void join(vector<int>& parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b) { return; }
        if (a < b) {
            parent[a] += parent[b];
            parent[b] = a;
        } else {
            parent[b] += parent[a];
            parent[a] = b;
        }
    }

    int find(vector<int>& parent, int value) {
        auto& par = parent[value];
        if (par < 0) { return value; }

        return par = find(parent, par);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}