// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int sz = parent.size();
        vector<vector<int>> nodes(sz);

        for (int i = 1; i < sz; ++i) { nodes[parent[i]].push_back(i); }

        string tmpStr;
        vector<pair<int, int>> strIndexes(sz);
        auto dfs = [&](auto& self, int x) -> void {
            strIndexes[x].first = tmpStr.size();
            for (int child : nodes[x]) { self(self, child); }
            tmpStr += s[x];
            strIndexes[x].second = tmpStr.size();
        };

        dfs(dfs, 0);

        int uniSz = 2 * sz + 1;
        string uniStr("^");
        uniStr.reserve(uniSz + 2);

        for (char c : tmpStr) { uniStr += '#'; uniStr += c; }
        uniStr += "#$";

        vector<int> wingSizes(uniSz);
        int start = 0; int stop = 0;
        for (int i = 2; i < uniSz; ++i) {
            int pal = 1;
            if (i < stop) { pal = min(wingSizes[2 * start - i], stop - i); }

            while (uniStr[i - pal] == uniStr[i + pal]) { ++pal; }

            if (i + pal > stop) {
                start = i;
                stop = i + pal;
            }

            wingSizes[i] = pal;
        }

        vector<bool> result;
        result.reserve(sz);
        for (auto& strIndex : strIndexes) {
            result.push_back(wingSizes[strIndex.first + strIndex.second + 1] > strIndex.second - strIndex.first);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}