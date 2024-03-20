// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> dependents;
        vector<int> depsCount(numCourses, 0);

        for (const auto& pre : prerequisites) {
            dependents[pre[1]].insert(pre[0]);
            ++depsCount[pre[0]];
        }

        deque<int> q;

        for (int i = 0; i < depsCount.size(); ++i) {
            if (depsCount[i] == 0) {
                q.push_back(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();

            for (int dep : dependents[i]) {
                if (--depsCount[dep] == 0) {
                    q.push_back(dep);
                }
            }

            dependents.erase(i);
            q.pop_front();
        }

        return dependents.empty();
    }
};

int main() {
    INIT_TIME(timer);
        
    PRINT_ELAPSED(timer);
    return 0;
}
