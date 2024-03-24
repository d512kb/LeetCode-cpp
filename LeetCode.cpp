// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> dependents;
        vector<int> depsCount(numCourses, 0);

        for (const auto& p : prerequisites) {
            dependents[p[1]].push_back(p[0]);
            ++depsCount[p[0]];
        }

        queue<int> q;
        vector<int> result;

        for (int i = 0; i < depsCount.size(); ++i) {
            if (depsCount[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int i = q.front();
            result.push_back(i);

            for (const auto& dep : dependents[i]) {
                if (--depsCount[dep] == 0) {
                    q.push(dep);
                }
            }

            q.pop();
        }

        if (result.size() != numCourses)
            result.clear();

        return result;
    }
};

int main() {
    INIT_TIME(timer);
        
    PRINT_ELAPSED(timer);
    return 0;
}
