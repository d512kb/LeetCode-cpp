// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> parents(26);
        iota(begin(parents), end(parents), 0);
        string result(baseStr.size(), 0);

        for (int i = 0; i < s1.size(); ++i) { join(parents, s1[i] - 'a', s2[i] - 'a'); }
        for (int i = 0; i < baseStr.size(); ++i) {
            result[i] = findParent(parents, baseStr[i] - 'a') + 'a';
        }

        return result;
    }
private:
    int findParent(vector<char>& parents, int c) {
        if (parents[c] == c) { return c; }
        parents[c] = findParent(parents, parents[c]);
        return parents[c];
    }
    void join(vector<char>& parents, int a, int b) {
        int aParent = findParent(parents, a);
        int bParent = findParent(parents, b);

        if (aParent > bParent) {
            parents[aParent] = bParent;
        } else {
            parents[bParent] = aParent;
        }
    }
};

int main() {
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}