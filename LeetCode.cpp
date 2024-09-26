// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int sz = strs.size();
        vector<int> parents(sz);
        iota(parents.begin(), parents.end(), 0);
        int result = sz;

        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (isSimilar(strs[i], strs[j]) && join(parents, i, j)) {
                    --result;
                }
            }
        }

        return result;
    }
private:
    int findParent(vector<int>& parents, int x) {
        if (parents[x] == x) { return x; }
        return parents[x] = findParent(parents, parents[x]);
    }
    inline bool join(vector<int>& parents, int a, int b) {
        int aParent = findParent(parents, a);
        int bParent = findParent(parents, b);

        if (aParent == bParent) {
            return false;
        } else {
            parents[bParent] = aParent;
            return true;
        }
    }
    bool isSimilar(const string& s1, const string& s2) {
        int sz = s1.size();
        int diff = 0;

        for (int i = 0; i < sz; ++i) {
            if (s1[i] != s2[i] && ++diff > 2) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}