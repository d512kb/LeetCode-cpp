// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(s.size());

        for (int i = 1; i < parent.size(); ++i) { graph[parent[i]].push_back(i); }
        int ans = 0;

        auto calcMaxPath = [&](auto&& self, int node) -> int {
            int longer = 0;
            int longest = 0;

            for (int child : graph[node]) {
                int length = self(self, child);

                if (s[node] != s[child]) {
                    if (length > longest) {
                        longer = longest;
                        longest = length;
                    } else if (length > longer) {
                        longer = length;
                    }
                }
            }

            ans = max(ans, longer + longest + 1);

            return 1 + longest;
        };

        calcMaxPath(calcMaxPath, 0);

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}