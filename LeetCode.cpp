// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parent(s.size(), -1);
        for (auto& p : pairs) { join(parent, p[0], p[1]); }

        unordered_map<int, vector<char>> sortedParts;
        for (int i = 0; i < parent.size(); ++i) {
            sortedParts[find(parent, i)].push_back(s[i]);
        }

        for (auto& ch : sortedParts) { sort(ch.second.begin(), ch.second.end(), greater<>()); }

        for (int i = 0; i < s.size(); ++i) {
            auto& sortedPart = sortedParts[find(parent, i)];

            s[i] = sortedPart.back();
            sortedPart.pop_back();
        }

        return s;
    }
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] < 0) { return x; }
        return parent[x] = find(parent, parent[x]);
    }

    void join(vector<int>& parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a != b) {
            if (parent[a] < parent[b]) { // a has a higher (negative) rank
                parent[b] = a;
            } else if (parent[b] < parent[a]) {
                parent[a] = b;
            } else {
                parent[a] = b;
                --parent[b];
            }
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}