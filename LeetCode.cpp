// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupsDependents(m + 1);
        vector<int> groupsDepsCount(m + 1);
        vector<vector<int>> itemsDependents(n);
        vector<int> itemsDepsCount(n);

        vector<queue<int>> queues(m + 1);

        for (int i = 0; i < n; ++i) {
            if (beforeItems[i].empty()) {
                queues[group[i] + 1].push(i);
            } else for (int req : beforeItems[i]) {
                itemsDependents[req].push_back(i);
                ++itemsDepsCount[i];

                int currGroup = group[i] + 1;
                int reqGroup = group[req] + 1;

                if (currGroup > 0 && reqGroup > 0 && currGroup != reqGroup) {
                    groupsDependents[reqGroup].push_back(currGroup);
                    ++groupsDepsCount[currGroup];
                }
            }
        }

        queue<int> groupsQueue;
        vector<int> result;

        for (int i = 0; i < m + 1; ++i) {
            if (groupsDepsCount[i] == 0) {
                groupsQueue.push(i);
            }
        }

        while (!groupsQueue.empty()) {
            int sz = groupsQueue.size();

            while (sz--) {
                int g = groupsQueue.front();
                groupsQueue.pop();

                for (int gDep : groupsDependents[g]) {
                    if (--groupsDepsCount[gDep] == 0) {
                        groupsQueue.push(gDep);
                    }
                }

                auto& q = queues[g];

                while (!q.empty()) {
                    int sz = q.size();

                    while (sz--) {
                        int item = q.front();
                        q.pop();

                        result.push_back(item);

                        for (int iDep : itemsDependents[item]) {
                            if (--itemsDepsCount[iDep] == 0) {
                                int g = group[iDep] + 1;

                                queues[g].push(iDep);
                                if (g == 0) { groupsQueue.push(g); }
                            }
                        }
                    }
                }
            }
        }

        return result.size() == n ? result : vector<int>();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}