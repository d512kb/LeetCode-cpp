// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const auto sz = favorite.size();
        vector<int> inDegree(sz);

        for (int i = 0; i < sz; ++i) {
            ++inDegree[favorite[i]];
        }

        queue<int> q;
        for (int i = 0; i < sz; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> depth(sz, 1);

        while (!q.empty()) {
            int node = q.front();
            int nextNode = favorite[node];
            q.pop();

            depth[nextNode] = max(depth[nextNode], 1 + depth[node]);
            if (--inDegree[nextNode] == 0) {
                q.push(nextNode);
            }
        }

        int peopleInChains = 0;
        int peopleInCycles = 0;

        for (int i = 0; i < sz; ++i) {
            if (inDegree[i] == 0) { continue; }

            int cycleLength = 0;
            for (int current = i; inDegree[current] > 0; current = favorite[current]) {
                inDegree[current] = 0;
                ++cycleLength;
            }

            if (cycleLength == 2) {
                peopleInChains += depth[i] + depth[favorite[i]];
            } else {
                peopleInCycles = max(peopleInCycles, cycleLength);
            }
        }

        return max(peopleInChains, peopleInCycles);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}