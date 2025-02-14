// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int sz = quiet.size();
        vector<vector<int>> graph(sz);
        vector<int> deps(sz);

        for (auto& rich : richer) {
            graph[rich[0]].push_back(rich[1]);
            ++deps[rich[1]];
        }

        queue<int> q;

        for (int i = 0; i < sz; ++i) {
            if (deps[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result(sz);
        iota(result.begin(), result.end(), 0);

        while (!q.empty()) {
            int id = q.front();
            int quietness = quiet[result[id]];
            q.pop();

            for (int sub : graph[id]) {
                if (quietness < quiet[result[sub]]) { result[sub] = result[id]; }
                if (--deps[sub] == 0) {
                    q.push(sub);
                }
            }
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